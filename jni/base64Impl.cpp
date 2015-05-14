/*
 * base64imp.c
 *
 *  Created on: 2015-5-14
 *      Author: zhiqiang.lei
 */

#include <string.h>
#include <stdio.h>
#include <jni.h>
#include "base64Impl.h"

int main(){
	return 0;
}

char* base64encode(const char* str){
	int len = strlen(str);
	int rel_len=(len/3)*4+4+1;
	char* rel;
	if(len<3){
		rel = (char*)malloc(5*sizeof(char));
	}else{
		rel = (char*)malloc(rel_len*sizeof(char));
	}
	//LOGD("num2base64char %d",rel_len);
	*(rel+rel_len-1) = '\0';
	*(rel+rel_len-2) = '\0';
	*(rel+rel_len-3) = '\0';
	*(rel+rel_len-4) = '\0';
	*(rel+rel_len-5) = '\0';
	int i=0;
	int j=0;
	//int n=0;
	for(i=0;i<len;){
		char* encode;
		if(i+2<=len-1){
			encode = translate3to4(*(str+i),*(str+i+1),*(str+i+2));
			*(rel+j) = num2base64char(*encode);
			*(rel+j+1) = num2base64char(*(encode+1));
			*(rel+j+2) = num2base64char(*(encode+2));
			*(rel+j+3) = num2base64char(*(encode+3));
		}else if(i == len-1){
			encode = translate3to4(*(str+i));
			*(rel+j) = num2base64char(*encode);
			*(rel+j+1) = num2base64char(*(encode+1));
			*(rel+j+2) = num2base64char(*(encode+2));
			*(rel+j+3) = num2base64char(*(encode+3));
		}else if(i+1 == len-1){
			encode = translate3to4(*(str+i),*(str+i+1));
			*(rel+j) = num2base64char(*encode);
			*(rel+j+1) = num2base64char(*(encode+1));
			*(rel+j+2) = num2base64char(*(encode+2));
			*(rel+j+3) = num2base64char(*(encode+3));
		}
		j+=4;
		i+=3;
		free(encode);
	}
	return rel;
}
char* translate3to4(char a,char b,char c){
	char* result = (char*)malloc(4*sizeof(char));
	*result = (a>>2)&0b00111111;
	*(result+1) = ((a<<4)&0b00110000)+((b>>4)&0b00001111);
	*(result+2) = ((c>>6)&0b00000011) + ((b<<2)&0b00111100);
	*(result+3) = c&0b00111111;
	return result;
}

char* translate3to4(char a){
	char* result = (char*)malloc(4*sizeof(char));
	*result = (a>>2)&0b00111111;
	*(result+1) = (a<<4)&0b00110000;
	*(result+2) = 64;
	*(result+3) = 64;
	return result;
}

char* translate3to4(char a,char b){
	char* result = (char*)malloc(4*sizeof(char));
	*result = (a>>2)&0b00111111;
	*(result+1) = ((a<<4)&0b00110000)+((b>>4)&0b00001111);
	*(result+2) = (b<<2)&0b00111100;
	*(result+3) = 64;
	return result;
}

char num2base64char(char n){
	char result;
	if(n<26){
		result = 'A'+n;
	}else if(n<52){
		result = 'a'+n-26;
	}else if(n<62){
		result = '0'+n-52;
	}else if(n==62){
		result = '+';
	}else if(n==63){
		result = '/';
	}else if(n==64){
		result = '=';
	}
	return result;
}

char* translate4to3(char a,char b,char c,char d){
	char* result = (char*)malloc(3*sizeof(char));
	*result =((a<<2)&0b11111100)+((b>>4)&0b00001111);
	*(result+1)=((c>>2)&0b00001111)+((b<<4)&0b11110000);
	*(result+2)=d+((c<<6)&0b11000000);

	return result;
}
char base64char2num(char b){
	char result;
	if(b>='A' && b<='Z'){
		result = b-'A';
	}else if(b>='a' && b<='z'){
		result = b-'a'+26;
	}else if(b>='0' && b<='9'){
		result = b-'0'+52;
	}else if(b=='+'){
		result = 62;
	}else if(b=='/'){
		result = 63;
	}else if(b=='='){
		result = 0;//64;
	}
	return result;
}
char* base64decode(const char* str){
	int len = strlen(str);
	int rel_len = (len/4)*3+1;
	char* rel = (char*)malloc(rel_len*sizeof(char));
	*(rel+rel_len-1)='\0';
	int i=0;
	int j=0;
	for(i=0;i<len;){
		if(i+3<=len-1){
			char* decode = translate4to3(base64char2num(*(str+i)),base64char2num(*(str+i+1)),base64char2num(*(str+i+2)),base64char2num(*(str+i+3)));
			if(*(str+i+3)!='='){
				*(rel+j)=*decode;
				*(rel+j+1)=*(decode+1);
				*(rel+j+2)=*(decode+2);
			}else if(*(str+i+2)!='='){
				*(rel+j)=*decode;
				*(rel+j+1)=*(decode+1);
				*(rel+j+2)='\0';
				break;
			}else{
				*(rel+j)=*decode;
				*(rel+j+1)='\0';
				*(rel+j+2)='\0';
				break;
			}
			free(decode);
		}
		i+=4;
		j+=3;
	}
	return rel;
}

