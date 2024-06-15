#include<stdio.h>
#include<string.h>   // includes strcat(), strlen(), strrev(), strcpy(), strcmp() functions

typedef long long ll;

int MAX = 100000;
char string[100000];

int main()
{
    char c[8] = {'h', 'e', 'l','l','o', '\0', 'i'};   // c[7] has garbage value.
    // char name[5] = "priyanshu";   // wrong output as arraya size is less than input.
    char name[20] = "priyanshu";     // vice-versa is okay to do... from name[9] to name[19] it stores garbage value. Size of name is always 20 bits
    char str[] = "pr hgh\0dew";       // automatically initializes the size of array equal to input size + 1(for \0). Size of str changes with input, rn it's 11 bits.

    // printf("%s \n", c);    //prints the whole array until '\0' is hit
    // printf("%s \n", str);  //prints the whole array until '\0' is hit
    // printf("%s \n", name);

    // int v[4] =  {1,2,3,4};   or just int v[] = {1,2,3,4};
    // printf("%d ", v);     //quite not the same functionality as that of character array, as their is no equivalent of %s here

    // scanf("%s", &c);   // scans only until it finds a white space(space, tab, enter). If array c gets full, it is resized to fit extra input.

    // scanf("%[^\n]s", c); // scan until you encounter newline([^\n]) and put it in c array(If array c gets full, it is resized to fit extra input.).
    // ^ is XOR operator which XOR's every character scanned one by one with '\n' and thus results true as both will be diffrent characters until the character scanned is itself '\n'.

    char temp;
    // scanf("%c", &temp);  // to clear the input buffer. After hitting enter(i.e newline), the input buffer would contain null char(\n)which gets scanned in below line 31 and it won't scan any further. So to prevent that we scan the null in temp variable and clear the input buffer first. We can also scan this after printing line 29, the input buffer remains intact until it is scanned from the console.

    // printf("%s**\n", c);

    // gets(string);   // reads characters string with white spaces until the array 'string' is full.
    // fgets(string, MAX, stdin);   // safer to use than gets() as it stops when either (MAX-1) characters are read, the newline character is read, or the end-of-file is reached, whichever comes first. It reads a line from the specified stream and stores it into the string pointed to by string, here the stream is stdin (standard input). It can also be from some file. fgets() might read newline '\n' when it encounters one and then stops scanning
    // size_t in = strlen(string) - 1;
    // if(string[in] == '\n'){
    //     string[in] = '\0';       // if last char is newline then change it to '\0'
    // }
    // printf("%s$$\n", string);

    // strcat()	   It is used to concatenate(combine) two strings
    // strlen()	   It is used to show the length of a string
    // strrev()	   It is used to show the reverse of a string
    // strcpy()    Copies one string into another
    // strcmp()    Compares two string. Returns the ASCII difference between first unmatching character of two strings.

    // strcat(str, name);    // concatenates and puts the resultant string in str.
    // printf("%s, %d, %d\n", str, strlen(str), strcmp(str, name));
    // strcpy(name, str); // copies content of str into name(as much it can store), erases preivous data of name
    // strrev(str);   // reverses str. The last character '\0' remains at last only to mark the position of termination. It is only to mark end of the string not a part of the string so it must not be reversed.
    
    // char *p = "avengers";    // sizeof(p) = 8
    // p = "avengersassemble";
    // printf("%s \n", p);

    // getchar() only takes a character from standard input. getc() can fetch a character from any input stream, e.g., files. Both used when single character input is required from the user(when multiple characters are inputted, it reads only first char). (reads as unsigned char and may cast into int when input stored in int and in EOF when end of file is found).
    // char t = getchar();  // the actual scanned character  // same as char t = getc(stdin);
    // int g = getchar();   // ASCII value of the scanned character
    // g = getchar();       // updates the value of g
    // printf("%c  %c  %d  %d\n", t, g, t, g);

    // A char is 1 byte = 8 bits, i.e a total of 2^8 = 256 different bit orientation, so a total of 256 characters can be represented via a char data type. Using ascii table we can know that which binary represntation and its corresponding decimal value refers to which character.

    char cr = -31;    // The C standard allows for compiler implementations to choose whether they consider char to be signed or unsigned. This compiler takes char as signed char. 256 - 31 = 225 is actual value in extended ascii for ß.

    // Signed char stores places from -128 to 127 position(represented in decimal). (-128 to -1) is extended ascii and 0 to 127 is usual ascii.
    // signed char c = 'd';   char c = 'a'; unsigned char c = '∩';  // all these are common in use.

    unsigned char dr = 236;   // Unsigned(0 to 255), (0 to 127) is usual ascii and (128 to 255) is extended ascii. Here, it takes the 236th ascii symbol(character) and inserts into dr. It's binary code is 11101100(236)    
    printf("%c, %d, %c, %d", cr, cr, dr, dr);

    // '5' has the int value 53(its ascii value)
    // if we write '5'-'0' it evaluates to 53-48, or the int 5
    // if we write char c = 'B'+32; then c stores 'b' or if char c = 'b' - 32; then c stores B now.

}