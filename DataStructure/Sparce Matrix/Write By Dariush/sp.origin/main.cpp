#if _WIN32
#   include "stdafx.h"
#   include <conio.h>
#else
#   include <cstdio>
#endif
#define __DEBUG__
#define __HUGE_DATA__
#include <time.h>
#include <memory>
#include <vector>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Term;
class Matrix_OF;

typedef Term* Matrix;

class MatrixInfo
{
public:
	size_t rowCount;
	size_t colCount;
	size_t size;
	MatrixInfo(size_t rowCount, size_t colCount, size_t size) {
		this->rowCount = rowCount;
		this->colCount = colCount;
		this->size = size;
	}
};

class Term
{
public:
	size_t row, col;
	double val;
public:
	Term(size_t _row, size_t _col, double _val)
	{
		row = _row;
		col = _col;
		val = _val;
	}
	Term(){}
	size_t	getRow() const { return this->row; }
	size_t	getCol() const { return this->col; }
	double	getVal() const { return this->val; }
};

class Matrix_OF
{
	const Matrix* matrix;
public:
	Matrix_OF(const Matrix* const m) { matrix = m; }
	~Matrix_OF() {
		for (size_t i = 0; i < this->getInfo().size; i++) delete this->matrix[i];
		delete this->matrix;
	}

	const Term* get(size_t i) const { return this->matrix[i]; }

	MatrixInfo getInfo()	const { return MatrixInfo(this->matrix[0]->getRow(), this->matrix[0]->getCol(), (size_t)this->matrix[0]->getVal()); }
	Matrix_OF* add(const Matrix_OF* const)	const;
	Matrix_OF* transpose(const Matrix_OF* const)	const;
	Matrix_OF* multiply(const Matrix_OF* const)	const;

	void print() const {
		for (size_t i = 0; i <= this->getInfo().size; i++)
		{
			std::cout << this->get(i)->getRow() << " " << this->get(i)->getCol() << " " << this->get(i)->getVal() << endl;
		}
	}
};


int main()
{
	Matrix* m1;
	Matrix* m2;
	size_t a, b, c;
	double d;
#ifdef __DEBUG__
	vector<int> v = {
#ifndef __HUGE_DATA__
		4, 4, 6,
		0, 1, 1,
		0, 2, 1,
		1, 0, 1,
		2, 1, 1,
		3, 1, 1,
		3, 3, 1,

		4, 4, 6,
		0, 0, 2,
		1, 0, 2,
		1, 3, 2,
		2, 1, 2,
		2, 3, 2,
		3, 1, 2,
#endif
	};
#ifdef __HUGE_DATA__
#define getRand(i, j) (i) + rand() % (j)
    vector<size_t> minfo1({ 10000, 100000, 10000 }), minfo2({ 1000, 10000, 100000 });
	v.push_back(minfo1[0]), v.push_back(minfo1[1]), v.push_back(minfo1[2]);
	srand(size_t(time(NULL)));
	for (size_t i = 0; i < minfo1[2]; i++)
	{
		v.push_back(getRand(0, minfo1[0]));
		v.push_back(getRand(0, minfo1[1]));
		v.push_back(getRand(0, minfo1[2]));
	}
	v.push_back(minfo2[0]), v.push_back(minfo2[1]), v.push_back(minfo2[2]);
	srand(size_t(time(NULL)));
	for (size_t i = 0; i < minfo2[2]; i++)
	{
		v.push_back(getRand(0, minfo2[0]));
		v.push_back(getRand(0, minfo2[1]));
		v.push_back(getRand(0, minfo2[2]));
	}
#undef getRand
#endif
	size_t vc = 0;
	a = v.at(vc++);
	b = v.at(vc++);
	c = v.at(vc++);
#else
	cin >> a >> b >> c;
#endif
	m1 = new Matrix[c + 1];
	m1[0] = new Term(a, b, c);
	for (size_t i = 1; i <= c; i++)
	{
#ifdef __DEBUG__
		a = v.at(vc++);
		b = v.at(vc++);
		d = v.at(vc++);
#else
		cin >> a >> b >> d;
#endif
		m1[i] = new Term(a, b, d);
	}
#ifdef __DEBUG__
	a = v.at(vc++);
	b = v.at(vc++);
	c = v.at(vc++);
#else
	cin >> a >> b >> c;
#endif
	m2 = new Matrix[c + 1];
	m2[0] = new Term(a, b, c);
	for (size_t i = 1; i <= c; i++)
	{
#ifdef __DEBUG__
		a = v.at(vc++);
		b = v.at(vc++);
		d = v.at(vc++);
#else
		cin >> a >> b >> d;
#endif
		m2[i] = new Term(a, b, d);
	}
	Matrix_OF* m3 = new Matrix_OF(m1);
	Matrix_OF* m4 = new Matrix_OF(m2);

#define printInfo(m5) cout << std::fixed << m5->getInfo().rowCount << " " << m5->getInfo().colCount << " " << m5->getInfo().size << endl
	cout << "M3" << endl;
#ifndef __HUGE_DATA__
	m3->print();
#else
	printInfo(m3);
#endif
	cout << "M4" << endl;
#ifndef __HUGE_DATA__
	m4->print();
#else
	printInfo(m4);
#endif
	cout << "******" << endl;
	auto m5 = m3->multiply(m4);
#ifndef __HUGE_DATA__
	m5->print();
#else
	printInfo(m5);
#endif

#undef printInfo
#if _WIN32
	_getch();
#else
    getchar();
#endif
	return 0;
}

Matrix_OF* Matrix_OF::add(const Matrix_OF* const m) const
{
	int p = 1, q = 1, o = 1;
	while (p <= this->matrix[0]->getVal() && q <= m->matrix[0]->getVal())
	{
		if (this->matrix[p]->getRow() == m->matrix[q]->getRow() && this->matrix[p]->getCol() == m->matrix[q]->getCol())
		{
			o++;
			p++;
			q++;
		}
		//compare rows with equal colom
		else if (this->matrix[p]->getRow() < m->matrix[q]->getRow())
		{
			o++;
			p++;
		}
		else if (this->matrix[p]->getRow() > m->matrix[q]->getRow())
		{
			o++;
			q++;
		}
		//compare coloms with equal row
		else if (this->matrix[p]->getCol() < m->matrix[q]->getCol() && this->matrix[p]->getRow() == m->matrix[q]->getRow())
		{
			o++;
			p++;
		}
		else if (this->matrix[p]->getCol() > m->matrix[q]->getCol() && this->matrix[p]->getRow() == m->matrix[q]->getRow())
		{
			o++;
			q++;
		}

	}

	while (p <= this->matrix[0]->getVal())
	{
		o++;
		p++;
	}

	while (q <= m->matrix[0]->getVal())
	{
		o++;
		q++;
	}

	o--;

	Matrix* sum = new Matrix[o];
	sum[0] = new Term(this->matrix[0]->getRow(), this->matrix[0]->getCol(), o);

	p = 1, q = 1, o = 1;

	double x;
	while (p <= this->matrix[0]->getVal() && q <= m->matrix[0]->getVal())
	{
		if (this->matrix[p]->getRow() == m->matrix[q]->getRow() && this->matrix[p]->getCol() == m->matrix[q]->getCol())
		{
			x = this->matrix[p]->getVal() + m->matrix[q]->getVal();
			sum[o] = new Term(this->matrix[p]->getRow(), this->matrix[q]->getCol(), x);
			o++;
			p++;
			q++;
		}
		//compare rows with equal colom
		else if (this->matrix[p]->getRow() < m->matrix[q]->getRow())
		{
			sum[o] = new Term(this->matrix[p]->getRow(), this->matrix[p]->getCol(), this->matrix[p]->getVal());
			o++;
			p++;
		}
		else if (this->matrix[p]->getRow() > m->matrix[q]->getRow())
		{
			sum[o] = new Term(m->matrix[q]->getRow(), m->matrix[q]->getCol(), m->matrix[q]->getVal());
			o++;
			q++;
		}
		//compare coloms with equal row
		else if (this->matrix[p]->getCol() < m->matrix[q]->getCol() && this->matrix[p]->getRow() == m->matrix[q]->getRow())
		{
			sum[o] = new Term(this->matrix[p]->getRow(), this->matrix[p]->getCol(), this->matrix[p]->getVal());
			o++;
			p++;
		}
		else if (this->matrix[p]->getCol() > m->matrix[q]->getCol() && this->matrix[p]->getRow() == m->matrix[q]->getRow())
		{
			sum[o] = new Term(m->matrix[q]->getRow(), m->matrix[q]->getCol(), m->matrix[q]->getVal());
			o++;
			q++;
		}

	}

	while (p <= this->matrix[0]->getVal())
	{
		sum[o] = new Term(this->matrix[p]->getRow(), this->matrix[p]->getCol(), this->matrix[p]->getVal());
		o++;
		p++;
	}

	while (q <= m->matrix[0]->getVal())
	{
		sum[o] = new Term(m->matrix[q]->getRow(), m->matrix[q]->getCol(), m->matrix[q]->getVal());
		o++;
		q++;
	}



	Matrix_OF* temp = new Matrix_OF(sum);

	return temp;
}
/**
* @brief Matrix_OF::transpose
* @param m
* @return
* @author Siavash   0
*                  /|\
*                  / \
* @note Written by dumb people :)
*/
Matrix_OF* Matrix_OF::transpose(const Matrix_OF* const m) const
{
	//size_t startposition = 0;
	size_t size = m->getInfo().size;
	Matrix* ans = new Matrix[size];
	ans[0] = new Term(m->getInfo().rowCount, m->getInfo().colCount, m->getInfo().size);
	int* a = new int[m->getInfo().colCount];
	//int startposition[10];
	int* startposition = new int[m->getInfo().colCount];
	for (size_t i = 0; i < m->getInfo().colCount; i++)
	{
		a[i] = 0;
	}
	for (size_t i = 0; i < m->getInfo().colCount; i++)
	{
		a[m->matrix[i]->getCol()]++;
	}
	startposition[0] = 1;
	for (size_t i = 1; i < m->getInfo().colCount; i++)
	{
		startposition[i] = startposition[i - 1] + a[i - 1];
	}
	int j = 0;
	for (size_t i = 1; i <= m->getInfo().colCount; i++)
	{
		j = startposition[m->matrix[i]->getCol()];
		ans[j] = new Term(m->matrix[i]->getCol(), m->matrix[i]->getRow(), m->matrix[i]->getVal());
		startposition[m->matrix[i]->getCol()]++;
	}
	return new Matrix_OF(ans);
}

/**
* @brief Multiplies current matrix with a secondary matrix
* @param m The secondary matrix
* @return The result of mult ops.
* @author Dariush /_O_\
*                   V
*                  / \
* @note Written for dumb people :)
*/
Matrix_OF* Matrix_OF::multiply(const Matrix_OF* const m) const
{
	auto row = this->getInfo().rowCount, col = m->getInfo().colCount;
	if (m->getInfo().colCount == this->getInfo().rowCount)
	{ row = m->getInfo().rowCount, col = this->getInfo().colCount; }
	class cellInfo {
	public:
		size_t i, j;
        vector<pair<size_t, size_t>> p;
        cellInfo(size_t i = -1, size_t j = -1) : i(i), j(j) { }
        void add(size_t i, size_t j) { this->p.push_back({ i, j }); }
        size_t getHash(size_t base = 10)  const { return this->i * base + this->j; }
    };
	// baraye negah dariye amare xane ha
    vector<cellInfo*>* stat = new vector<cellInfo*>();
	size_t counter = 0;
	for (size_t i = 1; i <= this->getInfo().size; i++)
    {
		for (size_t j = 1; j <= m->getInfo().size; j++)
		{
            auto x2 = m->matrix[j], x1 = this->matrix[i];
			if (x1->getCol() == x2->getRow())
			{
                auto point = std::find_if(stat->begin(), stat->end(), [&](const cellInfo* const c){
                    return (c->i == x1->getRow() && c->j == x2->getCol());
				});
                if (stat->size() == 0 || point == stat->end()){
					cellInfo* c = new cellInfo(x1->getRow(), x2->getCol());
					c->add(i, j);
                    stat->push_back(c);
				}
				else {
					/* index haye i & j dar hasele megdare xaneye [x1->getRow()][x2->getCol()] daxil mibashad */
					(*point)->add(i, j);
				}
			}
		}
	}
    std::sort(stat->begin(), stat->end(), [&](const cellInfo* const c1, const cellInfo* const c2) {
        return c1->getHash(stat->size()) < c2->getHash(stat->size());
	});
    Matrix* nm = new Matrix[stat->size()];
    nm[0] = new Term(row, col, stat->size());
	counter = 0;
    for(auto& xx: *stat) {
		double sum = 0;
		// ta zamani k xaneii baraye zarb vojud darad?
        for (auto& z: xx->p)
			// jame hasel zarbe [z.first] * [z.second]
			sum += this->matrix[z.first]->getVal() * m->matrix[z.second]->getVal();
		// ja gozari da makane monaseb dar Matrix*
		nm[++counter] = new Term(xx->i, xx->j, sum);
    }
	return new Matrix_OF(nm);
}
