// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#include "tset.h"

TBitField::TBitField(int len)
{MemLen = (len + 15) / 16;
 pMem   = new TELEM[MemLen];
if ( pMem != 0 )
    for ( int i=0; i < MemLen; i++ ) 
		pMem[i] = 0;
BitLen = len;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	TELEM *pMem2;
	pMem2 = new TELEM [bf.BitLen];
	for (int i=0;i < bf.MemLen; i++)
		pMem2[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
	delete []pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{return (1);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{return (1);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return (BitLen);
}

void TBitField::SetBit(const int n) // установить бит
{
}

void TBitField::ClrBit(const int n) // очистить бит
{
}

int TBitField::GetBit(const int n) const // получить значение бита
{
  return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{return (*x);
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  return (0);
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return(0);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{return(1);
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{return(1);
}

TBitField TBitField::operator~(void) // отрицание
{return(1);
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{return(istr);
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{return(ostr);
}
