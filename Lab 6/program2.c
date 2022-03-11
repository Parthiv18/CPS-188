#include <stdio.h>
#define ARRAY_SIZE 8

// finds the position of the smallest element in the subarray
// list[first] through list[last].
// Pre: first < last and elements 0 through last of array list are defined.
// Post: Returns the subscript k of the smallest element in the subarray;
// i.e., list[k] <= list[i] for all i in the subarray
int get_min_range(int list[], int first, int last) {
    /*
            4 5 2 1
            min = 0
            for loop until end of list + 1
                if (list[0] (4) <= list[min] (0) is (4))
                    min = i (in this case min=0)
            another run
                if (list[1] (5) <= list[min] (0) is 4)
                    min = i (in this case min=0)
            another run
                if (list[2] (2) <= list[min] (0) is 4)
                    min = i (in this case min=2)
            another run
                if (list[3] (1) <= list[min] (2) is 2)
                    min = i (in this case min=3)
    */

    int min = first;
    for (int i = first + 1; i < last + 1; i++) {
        // condittion => if list[i] is < the new minimum
        if (list[i] <= list[min]) {
            min = i;  // new index of min element
        }
    }
    return min;
}

// sorts the data in array list
void select_sort(int list[], int n) {
    int fill,         /* index of first element in unsorted subarray    */
        temp,         /* temporary storage                              */
        index_of_min; /* subscript of next smallest element             */

    for (fill = 0; fill < n - 1; ++fill) {
        /* Find position of smallest element in unsorted subarray */
        index_of_min = get_min_range(list, fill, n - 1);

        /* Exchange elements at fill and index_of_min */
        if (fill != index_of_min) {
            temp = list[index_of_min];
            list[index_of_min] = list[fill];
            list[fill] = temp;
        }
    }
}

int main(void) {
    int array[] = {67, 98, 23, 11, 47, 13, 94, 58};
    int i;

    select_sort(array, ARRAY_SIZE);

    for (i = 0; i < 8; ++i)
        printf("%d ", array[i]);

    return (0);
}
