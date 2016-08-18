// minnesmappning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>

HANDLE ut;
HANDLE in;
HANDLE map;


const TCHAR filnamn[]=TEXT("H:\\ÅR 2\\OSB304\\Labb06\\minnesmappning\\Debug\\storfil.txt");
const char* DATA;


int wmain( int argc, wchar_t *argv[ ], wchar_t *envp[ ] )
{
	in = CreateFile(filnamn, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	map = CreateFileMapping(in, NULL, PAGE_READONLY, 0, 0, NULL);
	DATA = static_cast<char*> (MapViewOfFile(map, FILE_MAP_READ, 0, 0, 0));
	

	int filesize;
	filesize = GetFileSize(in,NULL);
	printf("\nInfilens storlek= %i",filesize);
		
	
	int i;
	int count = 0;
	for(i=0; i < filesize; i++)
	{
		if(DATA[i] == 'a')
		{
		count++;
		}
	}
	printf("\nAntal 'a' i storfil.txt= %i",count);


	UnmapViewOfFile(map);
	CloseHandle(in);

return 0;
}

