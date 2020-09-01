void kmain(void)
{
	const char *str = "Welcome to FurkanOS";
	/* video memory baslangic adresi 0xb8000 */
	char *vidptr = (char*)0xb8000;
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int screensize;

	/* ekran temizleyen dongu
	* 25 satir 80 sutun bulunmakta; her element 2 byte */
	screensize = 80 * 25 * 2;
	while (j < screensize) {
		/* blank character : ekrani tamamen siyah kaplamak icin */
		vidptr[j] = ' ';
		/* attribute-byte : siyah background ve gri foreground icin */
		vidptr[j+1] = 0x07;
		j = j + 2;
	}

	j = 0;

	/* stringi video memory'e yazan dongu*/
	while (str[j] != '\0') {
		/* the character's ascii */
		vidptr[i] = str[j];
		/* attribute-byte: siyah background ve gri foreground icin */
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}

	return;
}


