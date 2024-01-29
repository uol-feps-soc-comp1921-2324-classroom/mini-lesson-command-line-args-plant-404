#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // Initialise array of valid digits
    char validDigits[] = "1234567890";

    // Validate commandline arguments
    if(argc != 3){
        printf("Wrong number of arguments.\n");
        printf("Usage: %s <integer> <integer>\n", argv[0]);
        return 1;
    }
    else{
        // Loop through arguments, check each character to ensure valid integer
        for(int i = 1; i < argc; i++){
            int charCount = 0;
            while(argv[i][charCount] != '\0'){
                // Set validCharacter true once we know character is a digit
                int validCharacter = 0;
                for(int digitCount = 0; digitCount < 10; digitCount++){
                    if(argv[i][charCount] == validDigits[digitCount]){
                        validCharacter = 1;
                    }
                }

                // On non-digit character found, output error and exit unsuccessfully
                if(!validCharacter){
                    printf("Non-integer input found.\n");
                    printf("Usage: %s <integer> <integer>\n", argv[0]);
                    return 0;
                }

                charCount++;
            }
        }

        // Arguments are valid, output sum
        printf("Sum: %d\n", atoi(argv[1]) + atoi(argv[2]));
    }

    return 0; // Exit successfully
}
