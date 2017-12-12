#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char tbl_flags_pages[16384];
int page_tbl[256];
char tbl_flags_frames[256];

int myContAlloc(int sg){
	int i, j;
	for (i = 0; i < (16384); i++){
		if (tbl_flags_pages[i] == 0){
			for (j = (i + 1); j< 16384 && j < (i + sg) && tbl_flags_pages[j] == 0; j++);
			if (j == i + sg){
				int k;
				for (k = i; (k < i + sg); k++){
					tbl_flags_pages[k] = 1;
				}
				return i; 
			} else{
				if (j == (i + sg)){
					i = (i + sg);
				}
			}
		}
	}
	return -1;
}

int myAlloc(int sg){
	int j;
	int i = myContAlloc(sg);
	if(i == -1)
		return -1;
	int first_page = i / 64;
	printf("This is the first page: %d\n", first_page);
	int last_page = (i + (sg - 1)) / 64;
	printf("This is the last page: %d\n", last_page);
	for (int k = first_page; k <= last_page; k++){
		if (page_tbl[k] == -1){
			// search for the frame
			for (j = 0; j < 256 && tbl_flags_frames[j] != 0; j++);
			if (j == 256){
				// not found 
				// deallocate slots in the logical memory
				// return -1
			}
			page_tbl[k] = j;
			printf("This is the frame: %d\n", j);
			tbl_flags_frames[k] = 1;
		}
	}
	return i;
}

void myWrite(int addr, char v){
	int page_nb = addr / 64;
	int frame_nb = page_tbl[page_nb];
	int offset = addr % 64;
	mem[(frame_nb * 64) + offset] = v;
}

int main(){
	int i;
	for (i = 0; i < (16384); i++){
		tbl_flags_pages[i] = 0;
	}
  
	for (i = 0; i < 256; i++){
		tbl_flags_frames[i] = 0;
		page_tbl[i] = -1;
	}

	int my_alloc = myAlloc(5);
	printf("%d \n", my_alloc);

	my_alloc = myAlloc(10);
	printf("%d\n", my_alloc);

	my_alloc = myAlloc(64);
	printf("%d\n", my_alloc);
	return 0;
}
