#include "../include/cesar.h"

/**
 https://www.thecrazyprogrammer.com/2016/11/caesar-cipher-c-c-encryption-decryption.html
*/
void cesar(char message[STR_LENGTH], int key) {
  for (int i = 0; message[i] != '\0'; ++i) {
    char ch = message[i];
    if (ch >= 'a' && ch <= 'z') {
      ch = ch - key;
      if (ch < 'a') {
        ch = ch + 'z' - 'a' + 1;
      }
      message[i] = ch;
    } else if (ch >= 'A' && ch <= 'Z') {
      ch = ch - key;
      if (ch < 'A') {
        ch = ch + 'Z' - 'A' + 1;
      }
      message[i] = ch;
    }
  }
}