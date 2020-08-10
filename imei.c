//gcc -o test.exe test4.c && ./test.exe
//gcc -o imei.exe test4.c && ./imei.exe 354190023896443

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t table[10] = {0,2,4,6,8,1,3,5,7,9};

uint8_t main(uint8_t argc, uint8_t *argv[]) {
  uint8_t *imei = argv[1];
  if(strlen(imei) != 15) { printf("Error imei"); return 0; }
  printf("%s", imei);
  uint8_t even=0, odd=0, crc;
  for(uint8_t i=0;i<14;i++) {
    if(i%2) {
      even += table[imei[i]-48];
    } else {
      odd += imei[i]-48;
    }
  }
  crc = (10-(even+odd)%10)%10;
  if(crc == imei[14]-48) printf(" crc valid\n"); else printf(" crc error %d\n", crc);

  return crc;
}
