#include <iostream>

/// Patches the main.dol of Metroid Prime to start new files at the ship on Tallon Overworld
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Invalid number of arguments provided, usage is 'primepatcher.exe [path to main.dol]'\nPress enter to exit");
		std::cin.get();
		return 1;
	}
	FILE *input = fopen(argv[1], "rb+");
	if(!input)
	{
		printf("An error occurred while trying to read file %s\nPress enter to exit", argv[1]);
		std::cin.get();
		return 1;
	}
	int const val1 = 0x39, val2 = 0xf3, val3 = 0xde, val4 = 0x28;
	fseek(input, 130846, std::ios::beg);
	fwrite(&val1, 1, 1, input);
	fseek(input, 130847, std::ios::beg);
	fwrite(&val2, 1, 1, input);
	fseek(input, 130858, std::ios::beg);
	fwrite(&val3, 1, 1, input);
	fseek(input, 130859, std::ios::beg);
	fwrite(&val4, 1, 1, input);
	fclose(input);
	printf("main.dol has been patched");
	return 0;
}