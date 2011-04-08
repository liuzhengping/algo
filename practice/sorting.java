	interface BinaryPredicate {
		boolean apply(int x, int y);
	}

	static class Sorting {

		private static final int partitionCutoff = 13;
		private static final int qsort_stacksize = 56;

		private static int quickPartition(int[] array, int first, int last,
				BinaryPredicate comp) {
			int f = array[first];
			int l = array[last - 1];
			int pivot = array[first + (last - first) / 2];

			if (comp.apply(pivot,f)) {
				if (comp.apply(f,l))
					pivot = f;
				else if (comp.apply(pivot,l))
					pivot = l;
			}
			else if (comp.apply(l,f))
				pivot = f;
			else if (comp.apply(l,pivot))
				pivot = l;

			--first;
			while (true) {
				while (comp.apply(array[++first], pivot))
				{ }

				while (comp.apply(pivot, array[--last]))
				{ }

				if (first >= last)
					return first;

				int tmp = array[first];
				array[first] = array[last];
				array[last] = tmp;
			}
		}

		private static void qsortLoop(int[] array, int first, int last,
				BinaryPredicate comp) {
			int[] stack = new int[qsort_stacksize];
			int position = 0;
			while (true) {
				int cut = quickPartition(array, first, last, comp);

				if (last - cut < partitionCutoff) {
					if (cut - first < partitionCutoff) {
						if (position == 0) 
							return;
						last = stack[--position];
						first = stack[--position];
					}
					else
						last = cut;
				}
				else if (cut - first <  partitionCutoff) { 
					first = cut; 
				}
				else if (last - cut > cut - first) {
					stack[position++] = cut;
					stack[position++] = last;
					last = cut;
				}
				else {
					stack[position++] = first;
					stack[position++] = cut;
					first = cut;
				} 
			}
		}

		static void insertion_sort(int[] array, int first, int last,
				BinaryPredicate comp) {
			for (int current = first; ++current < last; /* */ ) { 
				int tmp = array[current];
				int i = current;
				for (int tmp1 = array[i - 1];
				comp.apply(tmp, tmp1); 
				tmp1 = array[--i - 1] ) {
					array[i] = tmp1;
					if (first == i - 1) {
						--i;
						break;
					}
				}
				array[i] = tmp;
			}
		}

		static void sort(int[] array, int first, int last,
				BinaryPredicate comp) { 
			if (last - first >= partitionCutoff)
				qsortLoop(array, first, last, comp);
			insertion_sort(array, first, last, comp);
		}
	}

