#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb)(int a, int b);

/**
 * A classic bubble sort function that uses the 
 * compare_cb to do the sorting. 
 */
 // int sorted_order(int a, int b) replacing with compare_cb cmp || Pass in the wrong function for the and see what the C compiler complains compare_cb about.
int *bubble_sort(int *numbers, int count, compare_cb cmp) {
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if (!target)
        die("Memory error.");
        
    //https://www.geeksforgeeks.org/memcpy-in-cc/
    // void * memcpy(void *to, const void *from, size_t numBytes);
//    memcpy(target, numbers, count * sizeof(int));   
    memcpy(target, numbers, count * sizeof(int));   
    
    for (i = 0; i < count; i++) {
        for (j = 0; j < count - 1; j++) {
            if (cmp(target[j], target[j + 1]) > 0) {
                temp = target[j + 1];
                target[j + 1] = target[j];
                target[j] = temp;
            }
        }
    }
    return target;
}

int *insertionSort(int *numbers, int count, compare_cb cmp)
{
    int key;
    int i = 0;
    int j = 0;
    int *target_2 = malloc(count * sizeof(int));

    if (!target_2)
        die("Memory error.");

    memcpy(target_2, numbers, count * sizeof(int));

    for (i = 1; i < count; i++) {
        key = target_2[i];
        j = i - 1;
  
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && target_2[j] > key) {
            target_2[j + 1] = target_2[j];
            j = j - 1;
        }
        target_2[j + 1] = key;
    }
    return target_2;
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if (a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

/** 
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, compare_cb cmp)
{
    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp);
    int *in_Sort = insertionSort(numbers, count, cmp);

    //if (!sorted)
    if (!in_Sort || !sorted)
        die("Failed to sort as requested.");

    for (i = 0; i < count; i++) {
        printf("Bubble_SORT:: [%d] \n", sorted[i]);
    }

    printf("\n");

/*
    for (i = 0; i < count; i++) {
        printf("INsertion_SORT:: [%d] \n", in_Sort[i]);
    }
    printf("\n");
*/

   // printf("CMP print: %p \n", cmp);
    free(sorted);
    free(in_Sort);
}

void destroy(compare_cb cmp)
{
    int i = 0;

    unsigned char *data = (unsigned char *)cmp;

    for(i = 0; i < 1; i++) {
        data[i] = i;
    }

    printf("\n");
}

void dump(compare_cb cmp)
{
    int i = 0;
    printf("INSIDE_DUMP:: CMP print: %p \n \t", cmp);
    unsigned char *data = (unsigned char *)cmp;

    for(i = 0; i < 25; i++) {
        /* %x is a format specifier that format and output the hex value. If you are providing int or long value, it will convert it to hex value.
        %02x means if your provided value is less than two digits then 0 will be prepended.
        //https://stackoverflow.com/questions/18438946/format-specifier-02x
        */
        printf("%02x:", data[i]);
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2) die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if (!numbers) die("Memory error.");

    for (i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]); //https://www.geeksforgeeks.org/write-your-own-atoi/
    }

    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);

    free(numbers);
/*
    printf("SORTED:");
    dump(sorted_order);

//  destroy(sorted_order);

    printf("SORTED:");
    dump(sorted_order);
*/
    return 0;
}
