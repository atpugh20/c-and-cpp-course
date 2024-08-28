/* Double space input file to output file */

#include <stdio.h>
#include <stdlib.h>

void print_file(FILE *fptr) {
    /* prints the contents of the file */
    int c;
    rewind(fptr); // sets file position back to beginning
    while ((c = getc(fptr)) != EOF) {
        putc(c, stdout);
    }
}

void double_space(FILE *ifp, FILE *ofp) {
    /* Double spaces the input file and puts it into output file */
    int c;
    rewind(ifp);
    while((c = getc(ifp)) != EOF) {
        putc(c, ofp);
        if (c == '\n') putc('\n', ofp);
    }
}

int main(int argc, char *argv[]) {
    FILE *ifp, *ofp;
    
    // checks that there are 3 command line arguments (.exe data1 data2)
    if (argc != 3) {
        printf("Need executable inputfile outputfile\n");
        exit(1);
    }

    // open files from command line arguments
    ifp = fopen(argv[1], "r+"); //filename: data1
    ofp = fopen(argv[2], "w+"); //filename: data2
    
    // print first file
    printf("My %s file as read is:\n\n", argv[1]);
    print_file(ifp);
    printf("\n\n");

    // double space first file, then output it to second file
    double_space(ifp, ofp);
    printf("My %s file double spaced is:\n\n", argv[2]);
    print_file(ofp);
    printf("\n\n");
    
    fclose(ifp);
    fclose(ofp);

    return 0;
}
