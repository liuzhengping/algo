#!/usr/bin/python

from collections import namedtuple
from collections import defaultdict
import sys

Edge = namedtuple('Edge', ['cap', 'flow'])
Graph = namedtuple('Graph', ['v', 'adj'])
Cut = namedtuple('Cut', ['a', 'b'])

class EdgeProperties:
    def __init__(self, cap, flow=0):
        self.cap = cap
        self.flow = flow
    def __repr__(self):
        return "%s / %s" % (self.flow, self.cap)

def read_graph():
    g = Graph(set(), defaultdict(dict))
    for src, dst, cap in map(lambda s: s.split(), sys.stdin.readlines()):
        g.v.add(src)
        g.v.add(dst)
        g.adj[src][dst] = EdgeProperties(int(cap))
        g.adj[dst][src] = EdgeProperties(0)
    return g

def find_augmenting_path(gf, src, sink, path_edges):
#    print 'set =', path_edges
    if src == sink:
        return path_edges
    for dst, edge_prop in gf.adj[src].iteritems():
        edge = (src, dst)
        res_cap = edge_prop.cap - edge_prop.flow
        if res_cap > 0 and not edge in path_edges:
            path_edges.add(edge)
            augmenting_path = find_augmenting_path(gf, dst, sink, path_edges)
            path_edges.remove(edge)
            if augmenting_path is not None:
                augmenting_path.add((edge, res_cap))
                return augmenting_path

def compute_network_flow(g, source, sink):
    def get_flows(gf):
        return filter(lambda e: e[1] > 0,
                      [((src, dst), e.flow) for src, es in gf.adj.iteritems()
                       for dst, e in es.iteritems()])

    def cut_dfs(gf, src, visited):
        for dst, edge_prop in gf.adj[src].iteritems():
            if edge_prop.cap - edge_prop.flow > 0 and dst not in visited:
                visited.add(dst)
                cut_dfs(gf, dst, visited)

    gf = g
    while True:
        augmenting_path = find_augmenting_path(gf, source, sink, set())
        if augmenting_path is None:
            break
        flow = min(res_cap for _, res_cap in augmenting_path)
        print 'flow = %s' % flow
        for (src, dst), _ in augmenting_path:
            gf.adj[src][dst].flow += flow
            gf.adj[dst][src].flow -= flow
    max_flow = sum(ep.flow for _, ep in gf.adj[source].iteritems())

    cut_a = set(source)
    cut_dfs(gf, source, cut_a)
    cut = Cut(cut_a, gf.v - cut_a)
    return max_flow, get_flows(gf), cut

def main(args):
    source, sink = sys.stdin.readline().split()
    g = read_graph()
    print source, sink
    max_flow, flows, min_cut = compute_network_flow(g, source, sink)
    for e in flows:
        print 'flow%s = %s' % e
    print 'Max flow is %s' % max_flow
    print 'Min cut: ', min_cut

if __name__ == '__main__':
    main(sys.argv)
