#include<bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include<string>
#include<math.h>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define blockSize 4
#define SIZE 30
using namespace std;

string round_keys[16];
string pt;

string convertTextToBinary(const string& text)
{
    string binary = "";
    for (char c : text)
    {
        binary += bitset<8>(c).to_string();
    }
    return binary;
}

string convertBinaryToText(const string& binary)
{
    string text = "";
    for (size_t i = 0; i < binary.length(); i += 8)
    {
        string byte = binary.substr(i, 8);
        char c = static_cast<char>(bitset<8>(byte).to_ulong());
        text += c;
    }
    return text;
}

string convertDecimalToBinary(int decimal)
{
    string binary;
    while (decimal != 0)
    {
        binary = (decimal % 2 == 0 ? "0" : "1") + binary;
        decimal = decimal / 2;
    }
    while (binary.length() < 4)
    {
        binary = "0" + binary;
    }
    return binary;
}

int convertBinaryToDecimal(const string& binary)
{
    int decimal = 0;
    int counter = 0;
    int size = binary.length();
    for (int i = size - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += pow(2, counter);
        }
        counter++;
    }
    return decimal;
}

string shift_left_once(string key_chunk)
{
    string shifted = "";
    for (int i = 1; i < 28; i++)
    {
        shifted += key_chunk[i];
    }
    shifted += key_chunk[0];
    return shifted;
}

string shift_left_twice(string key_chunk)
{
    string shifted = "";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < 28; j++)
        {
            shifted += key_chunk[j];
        }
        shifted += key_chunk[0];
        key_chunk = shifted;
        shifted = "";
    }
    return key_chunk;
}

string Xor(string a, string b)
{
    string result = "";
    int size = b.size();
    for (int i = 0; i < size; i++)
    {
        if (a[i] != b[i])
        {
            result += "1";
        }
        else
        {
            result += "0";
        }
    }
    return result;
}

void generate_keys(string key)
{
    // The PC1 table
	int pc1[56] =
	{
        57,49,41,33,25,17,9,
        1,58,50,42,34,26,18,
        10,2,59,51,43,35,27,
        19,11,3,60,52,44,36,
        63,55,47,39,31,23,15,
        7,62,54,46,38,30,22,
        14,6,61,53,45,37,29,
        21,13,5,28,20,12,4
	};
	// The PC2 table
	int pc2[48] =
	{
        14,17,11,24,1,5,
        3,28,15,6,21,10,
        23,19,12,4,26,8,
        16,7,27,20,13,2,
        41,52,31,37,47,55,
        30,40,51,45,33,48,
        44,49,39,56,34,53,
        46,42,50,36,29,32
	};
	// 1. Compressing the key using the PC1 table
	string perm_key ="";
	for(int i = 0; i < 56; i++)
    {
		perm_key+= key[pc1[i]-1];
	}
	// 2. Dividing the key into two equal halves
	string left= perm_key.substr(0, 28);
	string right= perm_key.substr(28, 28);
	for(int i=0; i<16; i++)
	{
		// 3.1. For rounds 1, 2, 9, 16 the key_chunks
		// are shifted by one.
		if(i == 0 || i == 1 || i==8 || i==15 )
		{
			left= shift_left_once(left);
			right= shift_left_once(right);
		}
		// 3.2. For other rounds, the key_chunks
		// are shifted by two
		else
		{
			left= shift_left_twice(left);
			right= shift_left_twice(right);
		}
		// Combining the two chunks
		string combined_key = left + right;
		string round_key = "";
		// Finally, using the PC2 table to transpose the key bits
		for(int i = 0; i < 48; i++)
		{
			round_key += combined_key[pc2[i]-1];
		}
		round_keys[i] = round_key;
	}
}

string DES()
{
   // The initial permutation table
	int initial_permutation[64] =
	{
        58,50,42,34,26,18,10,2,
        60,52,44,36,28,20,12,4,
        62,54,46,38,30,22,14,6,
        64,56,48,40,32,24,16,8,
        57,49,41,33,25,17,9,1,
        59,51,43,35,27,19,11,3,
        61,53,45,37,29,21,13,5,
        63,55,47,39,31,23,15,7
	};
	// The expansion table
	int expansion_table[48] =
	{
        32,1,2,3,4,5,4,5,
        6,7,8,9,8,9,10,11,
        12,13,12,13,14,15,16,17,
        16,17,18,19,20,21,20,21,
        22,23,24,25,24,25,26,27,
        28,29,28,29,30,31,32,1
	};
	// The substitution boxes. The should contain values
	// from 0 to 15 in any order.
	int substition_boxes[8][4][16]=
	{
	    {
            14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
            0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
            4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
            15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
        },
        {
            15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
            3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
            0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
            13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
        },
        {
            10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
            13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
            13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
            1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
        },
        {
            7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
            13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
            10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
            3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
        },
        {
            2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
            14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
            4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
            11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
        },
        {
            12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
            10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
            9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
            4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
        },
        {
            4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
            13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
            1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
            6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
        },
        {
            13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
            1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
            7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
            2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
        }
    };
	// The permutation table
	int permutation_tab[32] =
	{
        16,7,20,21,29,12,28,17,
        1,15,23,26,5,18,31,10,
        2,8,24,14,32,27,3,9,
        19,13,30,6,22,11,4,25
	};
	// The inverse permutation table
	int inverse_permutation[64]=
	{
        40,8,48,16,56,24,64,32,
        39,7,47,15,55,23,63,31,
        38,6,46,14,54,22,62,30,
        37,5,45,13,53,21,61,29,
        36,4,44,12,52,20,60,28,
        35,3,43,11,51,19,59,27,
        34,2,42,10,50,18,58,26,
        33,1,41,9,49,17,57,25
	};
	//1. Applying the initial permutation
  	string perm = "";
	for(int i = 0; i < 64; i++)
    {
		perm += pt[initial_permutation[i]-1];
	}
	// 2. Dividing the result into two equal halves
	string left = perm.substr(0, 32);
	string right = perm.substr(32, 32);
	// The plain text is encrypted 16 times
	for(int i=0; i<16; i++)
	{
    	string right_expanded = "";
		// 3.1. The right half of the plain text is expanded
    	for(int i = 0; i < 48; i++)
    	{
      		right_expanded += right[expansion_table[i]-1];
        };  // 3.3. The result is xored with a key
		string xored = Xor(round_keys[i], right_expanded);
		string res = "";
		// 3.4. The result is divided into 8 equal parts and passed
		// through 8 substitution boxes. After passing through a
		// substituion box, each box is reduces from 6 to 4 bits.
		for(int i=0;i<8; i++)
		{
			// Finding row and column indices to lookup the
			// substituition box
      		string row1= xored.substr(i*6,1) + xored.substr(i*6 + 5,1);
      		int row = convertBinaryToDecimal(row1);
      		string col1 = xored.substr(i*6 + 1,1) + xored.substr(i*6 + 2,1) + xored.substr(i*6 + 3,1) + xored.substr(i*6 + 4,1);;
			int col = convertBinaryToDecimal(col1);
			int val = substition_boxes[i][row][col];
			res += convertDecimalToBinary(val);
		}
		// 3.5. Another permutation is applied
		string perm2 ="";
		for(int i = 0; i < 32; i++)
		{
			perm2 += res[permutation_tab[i]-1];
		}
		// 3.6. The result is xored with the left half
		xored = Xor(perm2, left);
		// 3.7. The left and the right parts of the plain text are swapped
		left = xored;
		if(i < 15)
		{
			string temp = right;
			right = xored;
			left = temp;
		}
	}
	// 4. The halves of the plain text are applied
	string combined_text = left + right;
	string ciphertext ="";
	// The inverse of the initial permuttaion is applied
	for(int i = 0; i < 64; i++)
	{
		ciphertext+= combined_text[inverse_permutation[i]-1];
	}
	//And we finally get the cipher text
	return ciphertext;
}

void getInputText(string& input, const string& prompt)
{
    cout << prompt << " : ";
    getline(cin, input);
}

string adjustBitLength(const string& input)
{
    string adjustedInput = input;

    // If length is less than 64, add 0s to the end
    while (adjustedInput.length() < 64)
    {
        adjustedInput += "0";
    }

    // If length is more than 64, trim to 64
    if (adjustedInput.length() > 64)
    {
        adjustedInput = adjustedInput.substr(0, 64);
    }

    return adjustedInput;
}

int power(int a, int b, int P)
{
    if (b == 1)
        return a;

    else
        return (((int)pow(a, b)) % P);
}

void toLowerCase(char plain[], int ps)
{
	int i;
	for (i = 0; i < ps; i++) {
		if (plain[i] > 64 && plain[i] < 91)
			plain[i] += 32;
	}
}

int removeSpaces(char* plain, int ps)
{
	int i, count = 0;
	for (i = 0; i < ps; i++)
		if (plain[i] != ' ')
			plain[count++] = plain[i];
	plain[count] = '\0';
	return count;
}

void generateKeyTable(char key[], int ks, char keyT[5][5])
{
	int i, j, k, flag = 0;

	// a 26 character hashmap
	// to store count of the alphabet
	int dicty[26] = { 0 };
	for (i = 0; i < ks; i++) {
		if (key[i] != 'j')
			dicty[key[i] - 97] = 2;
	}

	dicty['j' - 97] = 1;

	i = 0;
	j = 0;

	for (k = 0; k < ks; k++) {
		if (dicty[key[k] - 97] == 2) {
			dicty[key[k] - 97] -= 1;
			keyT[i][j] = key[k];
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}

	for (k = 0; k < 26; k++) {
		if (dicty[k] == 0) {
			keyT[i][j] = (char)(k + 97);
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}
}

void search(char keyT[5][5], char a, char b, int arr[])
{
	int i, j;

	if (a == 'j')
		a = 'i';
	else if (b == 'j')
		b = 'i';

	for (i = 0; i < 5; i++) {

		for (j = 0; j < 5; j++) {

			if (keyT[i][j] == a) {
				arr[0] = i;
				arr[1] = j;
			}
			else if (keyT[i][j] == b) {
				arr[2] = i;
				arr[3] = j;
			}
		}
	}
}

int mod5(int a)
{
	if (a < 0)
		a += 5;
	return (a % 5);
}

void decrypt(char str[], char keyT[5][5], int ps)
{
    int i, a[4];
    for (i = 0; i < ps; i += 2) {
        search(keyT, str[i], str[i + 1], a);
        if (a[0] == a[2]) {
            str[i] = keyT[a[0]][mod5(a[1] - 1)];
            str[i + 1] = keyT[a[0]][mod5(a[3] - 1)];
        }
        else if (a[1] == a[3]) {
            str[i] = keyT[mod5(a[0] - 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] - 1)][a[1]];
        }
        else {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

void decryptByPlayfairCipher(char str[], char key[])
{
    char ps, ks, keyT[5][5];

    // Key
    ks = strlen(key);
    ks = removeSpaces(key, ks);
    toLowerCase(key, ks);

    // ciphertext
    ps = strlen(str);
    toLowerCase(str, ps);
    ps = removeSpaces(str, ps);

    generateKeyTable(key, ks, keyT);

    decrypt(str, keyT, ps);
}

int prepare(char str[], int ptrs)
{
	if (ptrs % 2 != 0) {
		str[ptrs++] = 'z';
		str[ptrs] = '\0';
	}
	return ptrs;
}

void encrypt(char str[], char keyT[5][5], int ps)
{
	int i, a[4];

	for (i = 0; i < ps; i += 2) {

		search(keyT, str[i], str[i + 1], a);

		if (a[0] == a[2]) {
			str[i] = keyT[a[0]][mod5(a[1] + 1)];
			str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
		}
		else if (a[1] == a[3]) {
			str[i] = keyT[mod5(a[0] + 1)][a[1]];
			str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
		}
		else {
			str[i] = keyT[a[0]][a[3]];
			str[i + 1] = keyT[a[2]][a[1]];
		}
	}
}

void encryptByPlayfairCipher(char str[], char key[])
{
	char ps, ks, keyT[5][5];

	// Key
	ks = strlen(key);
	ks = removeSpaces(key, ks);
	toLowerCase(key, ks);

	// Plaintext
	ps = strlen(str);
	toLowerCase(str, ps);
	ps = removeSpaces(str, ps);

	ps = prepare(str, ps);

	generateKeyTable(key, ks, keyT);

	encrypt(str, keyT, ps);
}

string to_upper(string &in)
{
    for (int i = 0; i < in.length(); i++)
          if (islower(in[i]))
          if ('a' <= in[i] <= 'z')
              in[i] = in[i] - 'a' + 'A';
    return in;
}

void encryptMessage()
{
	int row,col,j;
	string key;
    cout<<" Masukkan Kunci Pesan : ";
	cin>>key;
    map<int,int> keyMap;
	string msg;
	cout<<" Masukkan Pesan :";
	cin>>msg;
	string cipher = "";

	// Add the permutation order into map
	for(int i=0; i < key.length(); i++)
	{
		keyMap[key[i]] = i;
	}
	/* calculate column of the matrix*/
	col = key.length();

	/* calculate Maximum row of the matrix*/
	row = msg.length()/col;

	if (msg.length() % col)
		row += 1;

	char matrix[row][col];

	for (int i=0,k=0; i < row; i++)
	{
		for (int j=0; j<col; )
		{
			if(msg[k] == '\0')
			{
				/* Adding the padding character '_' */
				matrix[i][j] = '_';
				j++;
			}

			if( isalpha(msg[k]) || msg[k]==' ')
			{
				/* Adding only space and alphabet into matrix*/
				matrix[i][j] = msg[k];
				j++;
			}
			k++;
		}
	}

	for (map<int,int>::iterator ii = keyMap.begin(); ii!=keyMap.end(); ++ii)
	{
		j=ii->second;

		// getting cipher text from matrix column wise using permuted key
		for (int i=0; i<row; i++)
		{
			if( isalpha(matrix[i][j]) || matrix[i][j]==' ' || matrix[i][j]=='_')
				cipher += matrix[i][j];
		}
	}
	// Calling encryption function
	cout << "Pesan yang Sudah di Columnar : " << cipher << endl<<endl;

	string binaryKey = convertTextToBinary(key); // Convert key and plain text to binary
    string binaryPlainText = convertTextToBinary(cipher); // Convert key and plain text to binary
    binaryKey = adjustBitLength(binaryKey); // Adjust bit length
    binaryPlainText = adjustBitLength(binaryPlainText); // Adjust bit length

    generate_keys(binaryKey);

    cout << "Plain Text: " << cipher << endl;

    pt = binaryPlainText;

    string cipherText = DES();

    cout << "Hasil Akhir Enkripsi Pesan : " << convertBinaryToText(cipherText) << endl;


}

void decryptMessage()
{
    string key, plainText, keyd, plainTextd;
    getInputText(key, "Masukkan Kunci Untuk DES ");

    // Get plain text input from the user
    getInputText(plainTextd, "Masukkan Plain Teks ");

    // Convert key and plain text to binary
    string binaryKeyd = convertTextToBinary(key);
    string binaryPlainTextd = convertTextToBinary(plainTextd);

    // Adjust bit length
    binaryKeyd = adjustBitLength(binaryKeyd);
    binaryPlainTextd = adjustBitLength(binaryPlainTextd);

    generate_keys(binaryKeyd);

    cout << "Plain Text: " << plainTextd << endl;

    pt = binaryPlainTextd;

    int i = 15;
    int j = 0;
    while (i > j)
    {
        string temp = round_keys[i];
        round_keys[i] = round_keys[j];
        round_keys[j] = temp;
        i--;
        j++;
    }

    string decryptedText = DES();

    // Convert binary to text
    string decryptedTextInText = convertBinaryToText(decryptedText);

    // Output in text format
    cout << "Hasil Dekripsi DES : " << decryptedTextInText << endl<< endl;

    map<int,int> keyMap;
	string plaintext = "";

	// Add the permutation order into map
	for(int i=0; i < key.length(); i++)
	{
		keyMap[key[i]] = i;
	}

 /* calculate row and column for cipher Matrix */
    int col = key.length();

    int row = decryptedTextInText.length()/col;
    char cipherMat[row][col];

    /* add character into matrix column wise */
    for (int j=0,k=0; j<col; j++)
        for (int i=0; i<row; i++)
            cipherMat[i][j] = decryptedTextInText[k++];

    /* update the order of key for decryption */
    int index = 0;
    for( map<int,int>::iterator ii=keyMap.begin(); ii!=keyMap.end(); ++ii)
        ii->second = index++;

    /* Arrange the matrix column wise according
    to permutation order by adding into new matrix */
    char decCipher[row][col];
    map<int,int>::iterator ii=keyMap.begin();
    int k = 0;
    for (int l=0,j; key[l]!='\0'; k++)
    {
        j = keyMap[key[l++]];
        for (int i=0; i<row; i++)
        {
            decCipher[i][k]=cipherMat[i][j];
        }
    }

    /* getting Message using matrix */
    for (int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(decCipher[i][j] != '_')
                plaintext += decCipher[i][j];
        }
    }
	// Calling encryption function
	cout << "Hasil Dekripsi Akhir : " << plaintext << endl;
}

int main()
{
int jawab;
menu:
     cout<<"  ****************************************************************  "<<endl;
     cout<<"               PROGRAM ALGORITMA DES DAN PLAYFAIR DAN               "<<endl;
     cout<<"   PEMBANGKITAN KUNCI MENGGUNAKAN COLUMNAR TRANSPOSITION DAN DES    "<<endl;
     cout<<"  ****************************************************************  "<<endl;
     cout<<"\t1.) Enkripsi Kunci\n";
     cout<<"\t2.) Enkripsi Pesan\n";
     cout<<"\t3.) Dekripsi Kunci\n";
     cout<<"\t4.) Dekripsi Pesan\n";
     cout<<"\t5.) Selesai\n";
     cout<<"\tSilahkan memilih menu sesuai nomor... "<<endl;
     cout<<"\tPilihan Anda: ";
	 cin>>jawab;
     cin.ignore(); // mengabaikan input spasi yang terjadi ketika input jawab tadi
     system("cls");
	switch(jawab)
	{
    case 1:
	{
	    string kunci,strply,keyd;
        char str[SIZE], key[SIZE];
	    cout<<"  ******************************************************************  "<<endl;
	    cout<<"                         ENKRIPSI KUNCI                               "<<endl;
	    cout<<"  ******************************************************************  "<<endl;
		cout<<"Masukkan Kunci Untuk Playfair : ";
		cin>>kunci;
		const int length = kunci.length();
        char* strkunci = new char[length + 1];
        strcpy(strkunci, kunci.c_str());
        strcpy(key, strkunci);

		cout<<"Masukkan Plainteks Kunci yang Ingin Dibangkitkan : ";
		cin>>strply;
		const int panjang = strply.length();
        char* strteks = new char[panjang + 1];
        strcpy(strteks, strply.c_str());
        strcpy(str, strteks);

		encryptByPlayfairCipher(str, key);

		cout<<"Hasil Pembangkitan Kunci Menggunakan Playfair: "<< str <<endl<<endl;

        cout << "Masukkan Kunci Untuk DES : ";
        cin >> keyd;

        string binaryKey = convertTextToBinary(keyd);
        string binaryPlainText = convertTextToBinary(str);

        binaryKey = adjustBitLength(binaryKey);
        binaryPlainText = adjustBitLength(binaryPlainText);

        generate_keys(binaryKey);
        pt = binaryPlainText;
        string cipherText = DES();

        cout << "Hasil Pembangkitan Kunci Akhir : " << convertBinaryToText(cipherText) << endl;

		getch();
        system("cls");
        goto menu;
	}
    case 2:
    {
        cout<<"  ******************************************************************  "<<endl;
	    cout<<"                         ENKRIPSI PESAN                               "<<endl;
	    cout<<"  ******************************************************************  "<<endl;
        encryptMessage();
        getch();
        system("cls");
        goto menu;
	}
    case 3:
    {
        string kuncid,strd,keywordd;
        char str[SIZE], key[SIZE];
        cout<<"  ******************************************************************  "<<endl;
	    cout<<"                         DEKRIPSI KUNCI                               "<<endl;
	    cout<<"  ******************************************************************  "<<endl;
		cout<<"Masukkan Kunci Untuk Dekripsi DES : ";
		cin>>kuncid;
		cout<<"Masukkan Plainteks Kunci : ";
		cin>>strd;

        string binaryKeyd = convertTextToBinary(kuncid);
        string binaryPlainTextd = convertTextToBinary(strd);

        binaryKeyd = adjustBitLength(binaryKeyd);
        binaryPlainTextd = adjustBitLength(binaryPlainTextd);

        generate_keys(binaryKeyd);

        pt = binaryPlainTextd;

        int i = 15;
        int j = 0;
        while (i > j)
        {
            string temp = round_keys[i];
            round_keys[i] = round_keys[j];
            round_keys[j] = temp;
            i--;
            j++;
        }

        string decryptedText = DES();

        // Convert binary to text
        string decryptedTextInText = convertBinaryToText(decryptedText);

        cout << "Hasil Dekripsi DES : " << decryptedTextInText << endl<<endl;

        string kuncip;
        cout<< "Masukkan Kunci Dekripsi Playfair : ";
        cin>>kuncip;

        const int length = decryptedTextInText.length();
        char* strp = new char[length + 1]; // declaring character array (+1 for null terminator)
        strcpy(strp, decryptedTextInText.c_str()); // copying the contents of the string to char array

        const int lengthk = kuncip.length();
        char* keyp = new char[lengthk + 1]; // declaring character array (+1 for null terminator)
        strcpy(keyp, kuncip.c_str());

        decryptByPlayfairCipher(strp, keyp);
        cout<<"Hasil Dekripsi Akhir : "<< strp <<endl;

        getch();
        system("cls");
        goto menu;
	}
    case 4:
    {
        cout<<"  ******************************************************************  "<<endl;
	    cout<<"                         DEKRIPSI PESAN                               "<<endl;
	    cout<<"  ******************************************************************  "<<endl;
        decryptMessage();
        getch();
        system("cls");
        goto menu;
	}
	case 5:
	{

        getch();
        system("cls");
        goto menu;
		}
	default:
        cout<<"\tPilihan Anda salah, silahkan coba kembali";
        system("cls");
        goto menu;
    }
}
