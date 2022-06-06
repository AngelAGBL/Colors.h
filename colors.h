/****************************************************
*	Librería de colores escrita por Ángel AGBL		*
*													*
*	GitHub: https://github.com/AngelAGBL			*
****************************************************/

# include <time.h>

void FG(int a) {printf("\x1B[38;2;%d;%d;%dm",(a >> 16) % 256,(a >> 8) % 256,(a >> 0) % 256);}		/// Colores de 24 bits de texto
void Fg(short a) {printf("\x1B[38;2;%d;%d;%dm",((a >> 8)%16)*16,((a >> 4)%16)*16,((a >> 0)%16)*16);}/// Colores de 12 bits de texto
void fG(unsigned __int8 a) {printf("\x1B[38;5;%dm",a);}			/// Colores de 8 bits de texto
void fg(__int8 s, __int8 a) {printf("\x1B[%dm",(a%8)+30+60*a);} /// Colores de 3 bits de texto

void BG(int a) {printf("\x1B[48;2;%d;%d;%dm",(a >> 16) % 256,(a >> 8) % 256,(a >> 0) % 256);}		/// Colores de 24 bits de fondo
void Bg(short a) {printf("\x1B[48;2;%d;%d;%dm",((a >> 8)%16)*16,((a >> 4)%16)*16,((a >> 0)%16)*16);}/// Colores de 12 bits de fondo
void bG(unsigned __int8 a) {printf("\x1B[48;5;%dm",a);}			/// Colores de 8 bits de fondo
void bg(__int8 s, __int8 a) {printf("\x1B[%dm",(a%8)+40+60*a);} /// Colores de 3 bits de fondo

void rst() {printf("\x1B[0m");}	///reiniciar font

void home() {printf("\x1B[H");}									/// Regresa el cursor a la posición 0,0
void MvCrTo(unsigned __int8 x,unsigned __int8 y) {printf("\x1B[%d;%dH",y,x);} /// Mueve el cursor a X, Y en la terminal
void MvU(unsigned __int8 x) {printf("\x1B[%dA",x);}				/// Mueve el cursor arriba
void MvD(unsigned __int8 x) {printf("\x1B[%dB",x);}				/// Mueve el cursor abajo
void MvR(unsigned __int8 x) {printf("\x1B[%dC",x);}				/// Mueve el cursor a la derecha
void MvL(unsigned __int8 x) {printf("\x1B[%dD",x);}				/// Mueve el cursor a la izquierda
void MvCrToCol(unsigned __int8 x) {printf("\x1B[%dG",x);}		/// Mueve el cursor a la columna X

void lj(__int8 n) {for (int i = 0; i<n; i++) printf("\n");} 	/// Inserta saltos de línea 'n' veces

void box2(char str[255]) {
	int i, l, a = 0, m = 0;
	for (l = 0; l <= 255 /*longitud char*/; l++) if (str[l] == '\0') break; //strlen
	
	for (i = 0; i <= l; i++)	// How many characters have the biggest line? Answer = 'm'
		if (str[i] == '\n' || str[i] == '\0') {
			if ((i - a) > m) m = i - a;
			a = i + 1;
	}
	
	printf("\n\xC9");for (int i = 0; i < m+2; i++) printf("\xCD"); printf("\xBB\n");
	
	a = 0;
	for (i = 0; i <= l; i++)	// Print of string in lines
		if (str[i] == '\n' || str[i] == '\0') {
			printf("\xBA ");
			for (int z = a; z < i; z++) printf("%c",str[z]);
			for (int z = 0; z < m + a - i; z++) printf(" ");
			printf(" \xBA");
			if (str[i] == '\n') printf("\n");
			if ((i - a) > m) m = i - a;
			a = i + 1;
	}
	
	printf("\n\xC8");for (int i = 0; i < m+2; i++) printf("\xCD"); printf("\xBC\n");
}

void box1(char str[255]) {
	int i, l, a = 0, m = 0;
	for (l = 0; l <= 255 /*longitud char*/; l++) if (str[l] == '\0') break; //strlen
	
	for (i = 0; i <= l; i++)	// How many characters have the biggest line? Answer = 'm'
		if (str[i] == '\n' || str[i] == '\0') {
			if ((i - a) > m) m = i - a;
			a = i + 1;
	}
		
	printf("\n\xDA");for (int i = 0; i < m+2; i++) printf("\xC4"); printf("\xBF\n");
	
	a = 0;
	for (i = 0; i <= l; i++)	// Print of string in lines
		if (str[i] == '\n' || str[i] == '\0') {
			printf("\xB3 ");
			for (int z = a; z < i; z++) printf("%c",str[z]);
			for (int z = 0; z < m + a - i; z++) printf(" ");
			printf(" \xB3");
			if (str[i] == '\n') printf("\n");
			if ((i - a) > m) m = i - a;
			a = i + 1;
	}
	
	printf("\n\xC0");for (int i = 0; i < m+2; i++) printf("\xC4"); printf("\xD9\n");
}

void box(char ch, char str[255]) {
	int i, l, a = 0, m = 0;
	for (l = 0; l <= 255 /*longitud char*/; l++) if (str[l] == '\0') break; //strlen
	
	for (i = 0; i <= l; i++)	// How many characters have the biggest line? Answer = 'm'
		if (str[i] == '\n' || str[i] == '\0') {
			if ((i - a) > m) m = i - a;
			a = i + 1;
	}
	
	printf("\n");for (int i = 0; i < m+6; i++) printf("%c",ch); printf("\n");
	
	a = 0;
	for (i = 0; i <= l; i++)	// Print of string in lines
		if (str[i] == '\n' || str[i] == '\0') {
			printf("%c%c ",ch,ch);
			for (int z = a; z < i; z++) printf("%c",str[z]);
			for (int z = 0; z < m + a - i; z++) printf(" ");
			printf(" %c%c",ch,ch);
			if (str[i] == '\n') printf("\n");
			if ((i - a) > m) m = i - a;
			a = i + 1;
	}
	
	printf("\n");for (int i = 0; i < m+6; i++) printf("%c",ch); printf("\n");
}

void esc(char a[3]) {											/// Función de códigos de escape
	int i,n;
	for (i = 0; i <= 3 /*longitud*/; i++) if (a[i] == '\0') break; //strlen
	for (int j = 0; j < i; j ++) if (a[j] < 48 || a[j] > 57) {i = 0; break;} //stringIsNumber
	
	if (i) {
		if (i == 1) n = a[0] - 48;
		if (i == 2) n = 10 * (a[0] - 48)+(a[1] - 48);
		if (i == 3) n = 100 * (a[0] - 48) + 10 * (a[1] - 48) + (a[2] - 48);
		printf("\x1B[%dm",n);
	} else {
		if (a[0] == 'r' && a[1] == 's' && a[2] == 't') printf("\x1B[0m");
		if (a[0] == 'b' && a[1] == 'l' && a[2] == 'd') printf("\x1B[1m");
		if (a[0] == 'f' && a[1] == 'n' && a[2] == 't') printf("\x1B[2m");
		if (a[0] == 'i' && a[1] == 't' && a[2] == 'l') printf("\x1B[3m");
		if (a[0] == 'u' && a[1] == 'n' && a[2] == 'd') printf("\x1B[4m");
		if (a[0] == 's' && a[1] == 'l' && a[2] == 'w') printf("\x1B[5m");
		if (a[0] == 'r' && a[1] == 'p' && a[2] == 'd') printf("\x1B[6m");
		if (a[0] == 's' && a[1] == 'w' && a[2] == 'p') printf("\x1B[7m");
		if (a[0] == 'c' && a[1] == 'n' && a[2] == 'c') printf("\x1B[8m");
		if (a[0] == 'c' && a[1] == 'r' && a[2] == 's') printf("\x1B[9m");
		if (a[0] == 'f' && a[1] == 'r' && a[2] == 'k') printf("\x1B[20m");
		if (a[0] == 'b' && a[1] == 'l' && a[2] == 'o') printf("\x1B[21m");
		if (a[0] == 'f' && a[1] == 'n' && a[2] == 'o') printf("\x1B[22m");
		if (a[0] == 'i' && a[1] == 't' && a[2] == 'o') printf("\x1B[23m");
		if (a[0] == 'u' && a[1] == 'n' && a[2] == 'o') printf("\x1B[24m");
		if (a[0] == 's' && a[1] == 'l' && a[2] == 'o') printf("\x1B[25m");
		if (a[0] == 's' && a[1] == 'w' && a[2] == 'o') printf("\x1B[27m");
		if (a[0] == 'r' && a[1] == 'v' && a[2] == 'l') printf("\x1B[28m");
		if (a[0] == 'n' && a[1] == 'c' && a[2] == 'r') printf("\x1B[29m");
		if (a[0] == 'd' && a[1] == 'f' && a[2] == 'g') printf("\x1B[39m");
		if (a[0] == 'd' && a[1] == 'b' && a[2] == 'g') printf("\x1B[49m");
		if (a[0] == 'f' && a[1] == 'r' && a[2] == 'm') printf("\x1B[51m");
		if (a[0] == 'e' && a[1] == 'n' && a[2] == 'c') printf("\x1B[52m");
		if (a[0] == 'o' && a[1] == 'v' && a[2] == 'r') printf("\x1B[53m");
		if (a[0] == 'n' && a[1] == 'f' && a[2] == 'r') printf("\x1B[54m");
		if (a[0] == 'n' && a[1] == 'o' && a[2] == 'v') printf("\x1B[55m");
		if (a[0] == 'c' && a[1] == 'l' && a[2] == 's') printf("\x1B[2J\x1B[H"); 	/// Limpia pantalla
		if (a[0] == 'c' && a[1] == 'l' && a[2] == 'l') printf("\x1B[2K\x1B[0G");	/// Limpia linea de texto
	}
}

void cls() {printf("\x1B[2J\x1B[H");}	/// Limpia pantalla
void cll() {printf("\x1B[2K\x1B[0G");}	/// Limpia línea de texto

void sleep(float secs) {				/// Espera durante 'secs' segundos
	int ms = secs * 1000000000;			// Soporte de valores decimales 'Ej. 0.5'
	struct timespec ts;
	ts.tv_sec = ms / 1000000000;
	ts.tv_nsec = ms % 1000000000;
	nanosleep(&ts, NULL);
}
