#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 200

void read_data(FILE *p_file, int d[], int *size) {
    /* reads the data and increments over 
     * size for each element in the file */
    int init[MAX_DATA];
    int counter = 0;
    while (fscanf(p_file, "%d", &init[counter]) == 1) {
        if (counter > 0) d[counter - 1] = init[counter];
        counter++;
    }
    *size = init[0];
}

void print_data(int d[], int size) {
    /* prints the file data in rows of 5 */
    printf("Data:\n\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", d[i]);
        if ((i + 1) % 5 == 0) printf("\n");
    }
    printf("\n\n");
}

double get_average(int data[], int size) {
    /* returns the average of an array */
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return (sum / size);
}

int get_max(int data[], int size) {
    /* returns the largest element in an array */
    int max = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

void save_stats(FILE *input, FILE *output, int max, double avg) {
    /* writes the numbers, max, and average from
     * the input file into the output file */
    int c;
    rewind(input);
    while((c = getc(input)) != EOF) {
        putc(c, output);
    }
    fprintf(output, "\n%d\n", max);
    fprintf(output, "%lf", avg);
}

int main(int argc, char *argv[]) {
    FILE *p_input_file, *p_output_file;
    int size = 0;
    int nums[MAX_DATA];

    // checks that there are 3 command line arguments
    if (argc != 3) {
        printf("Need executable input file and output file");
        exit(1);
    }
    
    // open files from command line arguments
    p_input_file = fopen(argv[1], "r+");  // filename num_data
    p_output_file = fopen(argv[2], "w+"); // filename num_data_out

    // get data and stats
    read_data(p_input_file, nums, &size);
    int max = get_max(nums, size);
    double average = get_average(nums, size);
    save_stats(p_input_file, p_output_file, max, average);
    
    // close the files
    fclose(p_input_file);
    fclose(p_output_file);

    // print data
    print_data(nums, size);
    printf("Largest number: %d\n", max);
    printf("Average: %lf\n", average);
    
    return 0;    
}
