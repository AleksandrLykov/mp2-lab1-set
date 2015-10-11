#include "tbitfield.h" 


TBitField::TBitField(int len) 
{ 
	MemLen = (len + 15) >> 4; 
	pMem = new TELEM[MemLen]; 
	for ( int i=0; i < MemLen; i++ ) 
		pMem[i] = 0; 
	BitLen = len;
} 

TBitField::TBitField(const TBitField &bf) // ����������� ����������� 
{ 
	BitLen = bf.BitLen; 
	MemLen = bf.MemLen; 
	pMem = new TELEM[MemLen]; 
	for (int i=0;i<MemLen;i++) 
		pMem[i] = bf.pMem[i]; 
} 

TBitField::~TBitField() 
{ 
	delete []pMem; 
} 

int TBitField::GetMemIndex(const int n) const // ������ ��� ��� ���� n 
{ 
	return n >> 4; 
} 

TELEM TBitField::GetMemMask(const int n) const // ������� ����� ��� ���� n 
{ 
	return 1 << (n & 15); 
} 

// ������ � ����� �������� ���� 

int TBitField::GetLength(void) const // �������� ����� (�-�� �����) 
{ 
	return (BitLen); 
} 

void TBitField::SetBit(const int n) // ���������� ��� 
{ 
	int a = GetMemIndex(n); 
	if ((n >= 0) && (n < BitLen)) { 
		pMem[a] = pMem[a] | GetMemMask(n);
	}
} 

void TBitField::ClrBit(const int n) // �������� ��� 
{ 
	int a = GetMemIndex(n); 
	if ((n >= 0) && (n < BitLen)) { 
		pMem[a] = pMem[a] & ~GetMemMask(n); 
	} 
} 

int TBitField::GetBit(const int n) const // �������� �������� ���� 
{ 
	int a = GetMemIndex(n); 
	if ((n >= 0) && (n < BitLen)) 
		return pMem[a] & GetMemMask(n); 
} 

// ������� �������� 

TBitField& TBitField::operator=(const TBitField &bf) // ������������ 
{ 
	BitLen = bf.BitLen; 
	MemLen = bf.MemLen; 
	delete []pMem; 
	pMem = new TELEM [MemLen]; 
	for (int i=0;i<MemLen;i++) { 
		pMem[i] = bf.pMem[i]; 
	} 
	return *this; 
} 

int TBitField::operator==(const TBitField &bf) const // ��������� 
{ 
	int a;
	if (MemLen == bf.MemLen) { 
	for (int i=0;i<MemLen;i++) { 
		if (pMem[i] != bf.pMem[i]) {
			a = 0;
			break;
		}
	}
	a = 1;
	}
	return a;
}
int TBitField::operator!=(const TBitField &bf) const // ��������� 
{ 
	int a; 
	if (MemLen == bf.MemLen) { 
		for (int i=0;i<MemLen;i++) { 
			if (pMem[i] = bf.pMem[i]) {
				a = 0; 
				break;
			}
		else a = 1; 
	}; 
}
return a; 
} 

TBitField TBitField::operator|(const TBitField &bf) // �������� "���" 
{ 
	int a; 
	if (BitLen >= bf.BitLen) a = BitLen; 
		else a = bf.BitLen; 
	TBitField x(a); 
	for (int i=0;i<x.MemLen;i++) { 
		x.pMem[i] = bf.pMem[i] | pMem[i]; 
	} 
	return x; 
} 

TBitField TBitField::operator&(const TBitField &bf) // �������� "�" 
{ 
	int a; 
	if (BitLen >= bf.BitLen) a = BitLen; 
	else a = bf.BitLen; 
	TBitField x(a); 
	for (int i=0;i<x.MemLen;i++) { 
		x.pMem[i] = bf.pMem[i] & pMem[i]; 
	} 
	return x; 
} 

TBitField TBitField::operator~(void) // ��������� 
{ 
	int a = BitLen; 
	TBitField x(a); 
	for (int i=0;i < MemLen;i++) { 
		x.pMem[i] = ~pMem[i]; 
	} 
	return x; 
} 

// ����/����� 

istream &operator>>(istream &istr, TBitField &bf) // ���� 
{ 
for (int i=0;i<bf.MemLen;i++) { 
istr >> bf.pMem[i]; 
} 
return istr; 
} 


ostream &operator<<(ostream &ostr, const TBitField &bf) // ����� 
{ 
for (int i=0; i<bf.MemLen;i++) { 
ostr << bf.pMem[i]; 
} 
return ostr; 
}