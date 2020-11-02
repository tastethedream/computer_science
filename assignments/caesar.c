#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool validate_key(string s);
void encrypt(string plaintext, string ciphertext, int k);

int main(int argc, string argv[])
{
    //command line argument 0 will be the name of the program and 1 will be the key so....
    if (argc != 2 || !validate_key(argv[1])) 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //atio converts string to int
    int k = atoi(argv[1]);
    string s = get_string("Plaintext: ");
    int n = strlen(s);
    //n + 1 to account for the null char
    char ciphertext[n + 1];
    encrypt(s, ciphertext, k);
    
    printf("ciphertext: %s\n", ciphertext);
    
    return 0;    
}

void encrypt(string plaintext, string ciphertext, int k) 
{

    int i = 0;
    for (i = 0; i < strlen(plaintext); i++) 
    {
        char ch = plaintext[i];
        
        //encrypt the plain text 
        if (isalpha(ch)) 
        {
//temporarily change all text to lower case
            char lower = tolower(ch);
            int pi = lower - 'a';
            char ci = ((pi + k) % 26) + 'a';
            //check if there were any uppercase chars in text and covert them back
            ciphertext[i] = islower(ch) ? ci : toupper(ci);
        } 
        else 
        {
//if not an alphabetical char do not do anything
            ciphertext[i] = ch;
        }
    }
    
    ciphertext[i] = '\0';
}
//function to validate key
bool validate_key(string s) 
{
    for (int i = 0; i < strlen(s); i++) 
    {
        char ch = s[i];
        if (!isdigit(ch)) 
        {
            return false;
        } 
    }
    return true;
}