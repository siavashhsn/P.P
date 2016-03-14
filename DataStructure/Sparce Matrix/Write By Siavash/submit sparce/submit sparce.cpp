#include "stdafx.h"
#include <conio.h>
#include <vector>
#include <iostream>
#include <algorithm>
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

///////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////

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
	Matrix_OF* multiply(const Matrix_OF* const) 	const;
	Matrix_OF* multiply2(const Matrix_OF* const)	const;

	void print() const {
		for (size_t i = 0; i <= this->getInfo().size; i++)
		{
			cout << this->get(i)->getRow() << " " << this->get(i)->getCol() << " " << this->get(i)->getVal() << endl;
		}
	}
};

///////////////////////////////////////////////////////////////////

int main()
{

	Matrix* m1;
	Matrix* m2;
	size_t a, b, c;
	double d;
	cin >> a >> b >> c;
	m1 = new Matrix[c + 1];
	m1[0] = new Term(a, b, c);
	cin >> a >> b >> c;
	m2 = new Matrix[c + 1];
	m2[0] = new Term(a, b, c);
	for (size_t i = 1; i <= m1[0]->getVal(); i++)
	{
		cin >> a >> b >> d;
		m1[i] = new Term(a, b, d);
	}
	for (size_t j = 1; j <= m2[0]->getVal(); j++)
	{
		cin >> a >> b >> d;
		m2[j] = new Term(a, b, d);
	}

	Matrix_OF* m3 = new Matrix_OF(m1);
	Matrix_OF* m4 = new Matrix_OF(m2);

	char operand;
	cin >> operand;
	if (operand == '*')
	{
		auto m5 = m3->multiply2(m4);
		m5->print();
	}
	else if (operand == '+')
	{
		auto m5 = m3->add(m4);
		m5->print();
	}
	else if (operand == '\'')
	{
		auto m5 = m3->transpose(m3);
		m5->print();
	}


	_getch();

	return 0;
}

///////////////////////////////////////////////////////////////////

Matrix_OF* Matrix_OF::add(const Matrix_OF* const m) const
{
	int p = 1, q = 1, o = 1;
	while (p <= this->matrix[0]->getVal() && q <= m->matrix[0]->getVal())
	{
		if (this->matrix[p]->getRow() == m->matrix[q]->getRow())
		{
			if (this->matrix[p]->getCol() == m->matrix[q]->getCol())
			{
				if (this->matrix[p]->getVal() + m->matrix[q]->getVal() != 0)
					o++;
				p++;
				q++;
			}
			else if (this->matrix[p]->getCol() < m->matrix[q]->getCol())
			{
				o++;
				p++;
			}
			else if (this->matrix[p]->getCol() > m->matrix[q]->getCol())
			{
				o++;
				q++;
			}
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

	Matrix* sum = new Matrix[o + 1];
	sum[0] = new Term(this->matrix[0]->getRow(), this->matrix[0]->getCol(), o);

	p = 1, q = 1, o = 1;

	double x;
	while (p <= this->matrix[0]->getVal() && q <= m->matrix[0]->getVal())
	{
		if (this->matrix[p]->getRow() == m->matrix[q]->getRow() /*&& this->matrix[p]->getCol() == m->matrix[q]->getCol()*/)
		{
			if (this->matrix[p]->getCol() == m->matrix[q]->getCol())
			{

				x = this->matrix[p]->getVal() + m->matrix[q]->getVal();
				if (x != 0)
				{
					sum[o] = new Term(this->matrix[p]->getRow(), this->matrix[p]->getCol(), x);
					o++;
				}
				p++;
				q++;
			}
			else if (this->matrix[p]->getCol() < m->matrix[q]->getCol())
			{
				sum[o] = new Term(this->matrix[p]->getRow(), this->matrix[p]->getCol(), this->matrix[p]->getVal());
				o++;
				p++;
			}
			else if (this->matrix[p]->getCol() > m->matrix[q]->getCol())
			{
				sum[o] = new Term(m->matrix[q]->getRow(), m->matrix[q]->getCol(), m->matrix[q]->getVal());
				o++;
				q++;
			}
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

Matrix_OF* Matrix_OF::transpose(const Matrix_OF* const m) const
{
	//size_t startposition = 0;
	size_t size = m->getInfo().size;
	Matrix* ans = new Matrix[size + 1];
	ans[0] = new Term(m->getInfo().colCount, m->getInfo().rowCount, m->getInfo().size);
	int* a = new int[m->getInfo().colCount];
	int* startposition = new int[m->getInfo().colCount];
	for (size_t i = 0; i < m->getInfo().colCount; i++)
	{
		a[i] = 0;
	}
	for (size_t i = 1; i <= m->getInfo().size; i++)
	{
		a[m->matrix[i]->getCol()]++;
	}
	startposition[0] = 1;
	for (size_t i = 1; i < m->getInfo().colCount; i++)
	{
		startposition[i] = startposition[i - 1] + a[i - 1];
	}
	int j = 0;
	for (size_t i = 1; i <= m->getInfo().size; i++)
	{
		j = startposition[m->matrix[i]->getCol()];
		ans[j] = new Term(m->matrix[i]->getCol(), m->matrix[i]->getRow(), m->matrix[i]->getVal());
		startposition[m->matrix[i]->getCol()]++;
	}
	return new Matrix_OF(ans);
}

Matrix_OF* Matrix_OF::multiply(const Matrix_OF* const mm) const
{
	auto row = this->getInfo().rowCount, col = mm->getInfo().colCount;
	if (this->getInfo().rowCount == mm->getInfo().colCount)
	{
		row = mm->getInfo().rowCount, col = this->getInfo().colCount;
	}
	class cellInfo {
	public:
		size_t i, j;
		vector<pair<size_t, size_t> > p;
		cellInfo(size_t i, size_t j) : i(i), j(j) { }
		void add(size_t i, size_t j) { this->p.push_back({ i, j }); }
		size_t getHash(size_t base) const { return this->i * base + this->j; }
	};

	vector<cellInfo*>* stat = new vector<cellInfo*>();
	size_t counter = 0;
	for (size_t i = 1; i <= this->getInfo().size; i++)
	{
		for (size_t j = 1; j <= mm->getInfo().size; ++j)
		{
			if (this->matrix[i]->getCol() == mm->matrix[j]->getRow())
			{
				size_t k = 0;
				for (; k < stat->size(); k++) {
					if ((*stat)[k]->i == this->matrix[i]->getRow() && (*stat)[k]->j == mm->matrix[j]->getCol())
					{
						(*stat)[k]->add(i, j);
						break;
					}
				}
				if (k == stat->size())
				{
					cellInfo* c = new cellInfo(this->matrix[i]->getRow(), mm->matrix[j]->getCol());
					c->add(i, j);
					stat->push_back(c);
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
	for (size_t i = 0; i < stat->size(); i++) {
		auto xx = (*stat)[i];
		double sum = 0;
		for (size_t j = 0; j < xx->p.size(); j++){
			auto z = xx->p[j];
			sum += this->matrix[z.first]->getVal() * mm->matrix[z.second]->getVal();
		}
		nm[++counter] = new Term(xx->i, xx->j, sum);
	}
	return new Matrix_OF(nm);
}

Matrix_OF* Matrix_OF::multiply2(const Matrix_OF* const m) const
{
	Matrix_OF* n = m->transpose(m);

	size_t begin;
	int currentRow;
	int currentCol;
	int nextCurrentRow;
	int lastCurrentRow;

	if (this->getInfo().size != 0)
		lastCurrentRow = this->matrix[this->getInfo().size]->getRow();
	else
		lastCurrentRow = -1;

	if (this->getInfo().size != 0)
		nextCurrentRow = this->matrix[1]->getRow();
	else
		nextCurrentRow = -1;

	double sum = 0;

	if (this->getInfo().rowCount == 0 && this->getInfo().colCount == 0)
	{
		Matrix* ans = new Matrix[1];
		ans[0] = new Term(0, 0, 0);
		return new Matrix_OF(ans);
	}

	if (n->getInfo().rowCount == 0 && n->getInfo().colCount == 0)
	{
		Matrix* ans = new Matrix[1];
		ans[0] = new Term(0, 0, 0);
		return new Matrix_OF(ans);
	}

	begin = 1;
	if (this->getInfo().size != 0)
		currentRow = this->matrix[1]->getRow();
	else
		currentRow = -1;
	if (n->getInfo().size != 0)
		currentCol = n->matrix[1]->getRow();
	else
		currentCol = -1;
	size_t i = 1, j = 1, k = 1, counter = 0;

	bool aaaaaaa = true;


	///////////////////////////declaration size of ans matrix///////////////////////////////

	while (i <= this->getInfo().size && j <= n->getInfo().size)
	{
		while (j <= n->getInfo().size)
		{
			//auto xx = this->getInfo().size;
			while (this->matrix[i]->getRow() == currentRow && j <= n->getInfo().size)
			{
				j;
				auto x = n->matrix[j]->getRow();
				if (x == currentCol)
				{
					x = n->matrix[j]->getCol();
					if (this->matrix[i]->getCol() == n->matrix[j]->getCol())
					{
						sum += this->matrix[i]->getVal() * n->matrix[j]->getVal();
						i++;
						j++;
					}
					else if (this->matrix[i]->getCol() > n->matrix[j]->getCol())
					{
						j++;
					}
					else if (this->matrix[i]->getCol() < n->matrix[j]->getCol())
					{
						i++;
					}
				}
				else
				{
					if (sum != 0)
					{
						counter++;
					}
					sum = 0;
					i = begin;
					currentCol = n->matrix[j]->getRow();
				}

				if (i > this->getInfo().size)
					break;
				/*if (this->matrix[i]->getRow() != currentRow)
				{
					nextCurrentRow = this->matrix[i]->getRow();
				}*/
				if (j > n->getInfo().size)
					break;
			}//end of third while

			//auto xxx = this->matrix[i]->getRow();
			/*if (i <= this->getInfo().size)
			if (this->matrix[i]->getRow() != currentRow)
			nextCurrentRow = this->matrix[i]->getRow();*/

			if (sum == 0)
				j++;
			if (sum != 0)
				counter++;
			if (currentRow == this->matrix[this->getInfo().size]->getRow() && j>n->getInfo().size)
				aaaaaaa = false;
			sum = 0;

			if (j > n->getInfo().size)
			{
				break;
			}

			i = begin;
			currentCol = n->matrix[j]->getRow();

		}//end of second while  ->  (j <= n->getInfo().size)

		if (i > this->getInfo().size)
			break;
		/*if (nextCurrentRow == lastCurrentRow && j > n->getInfo().size)
		break;*/
		//size_t o= 1;
		/*while (nextCurrentRow != this->matrix[o]->getRow())
		o++;*/
		//nextCurrentRow = this->matrix[o]->getRow();
		if (aaaaaaa == false)
			break;
		i = 1;
		while (this->matrix[i]->getRow() <= currentRow)
			i++;
		begin = i;
		currentRow = this->matrix[i]->getRow();
		j = 1;
		currentCol = n->matrix[j]->getRow();
	}//end of first while

	counter;
	///////////////////////////////////////////////////////////////////////////////////////


	Matrix* ans = new Matrix[counter + 1];  //////////   m changed to n   //////////
	ans[0] = new Term(this->getInfo().rowCount, n->getInfo().rowCount, counter);
	sum = 0;
	begin = 1;
	i = 1, j = 1, k = 1;

	if (this->getInfo().size != 0)
		lastCurrentRow = this->matrix[this->getInfo().size]->getRow();
	else
		lastCurrentRow = -1;

	if (this->getInfo().size != 0)
		nextCurrentRow = this->matrix[1]->getRow();
	else
		nextCurrentRow = -1;

	if (this->getInfo().size != 0)
		currentRow = this->matrix[1]->getRow();
	else
		currentRow = 0;

	if (n->getInfo().size != 0)
		currentCol = n->matrix[1]->getRow();
	else
		currentCol = 0;
	bool aaaaaaaaa = true;

	while (i <= this->getInfo().size && j <= n->getInfo().size)
	{
		while (j <= n->getInfo().size)
		{
			//auto xx = this->getInfo().size;
			while (this->matrix[i]->getRow() == currentRow && j <= n->getInfo().size)
			{
				auto x = n->matrix[j]->getRow();
				if (x == currentCol)
				{
					x = n->matrix[j]->getCol();
					if (this->matrix[i]->getCol() == n->matrix[j]->getCol())
					{
						sum += this->matrix[i]->getVal() * n->matrix[j]->getVal();
						i++;
						j++;
					}
					else if (this->matrix[i]->getCol() > n->matrix[j]->getCol())
					{
						j++;
					}
					else if (this->matrix[i]->getCol() < n->matrix[j]->getCol())
					{
						i++;
					}
				}
				else
				{
					if (sum != 0)
					{
						ans[k] = new Term(currentRow, currentCol, sum);
						auto xxxxx = ans[k]->getVal();
						k++;
						sum = 0;
					}
					i = begin;
					currentCol = n->matrix[j]->getRow();
				}


				if (i > this->getInfo().size)
					break;
				/*if (this->matrix[i]->getRow() != currentRow)
				{
					nextCurrentRow = this->matrix[i]->getRow();

				}*/

				if (j > n->getInfo().size)
					break;

			}//end of third while

			//auto xxx = this->matrix[i]->getRow();
			/*if (i <= this->getInfo().size)
			if (this->matrix[i]->getRow() != currentRow)
			nextCurrentRow = this->matrix[i]->getRow();*/

			if (sum == 0)
				j++;
			else if (sum != 0)
			{
				ans[k] = new Term(currentRow, currentCol, sum);
				auto xxxxxx = new Term(ans[k]->getRow(), ans[k]->getCol(), ans[k]->getVal());
				k++;
			}
			if (currentRow == this->matrix[this->getInfo().size]->getRow() && j>n->getInfo().size)
				aaaaaaaaa = false;
			sum = 0;

			if (j > n->getInfo().size)
			{
				break;
			}

			i = begin;
			currentCol = n->matrix[j]->getRow();

		}//end of second while  ->  (j <= n->getInfo().size)


		if (i > this->getInfo().size)
			break;
		/*if (nextCurrentRow == lastCurrentRow && j > n->getInfo().size)
		break;*/
		/*size_t o = 1;
		while (nextCurrentRow != this->matrix[o]->getRow())
		o++;
		nextCurrentRow = this->matrix[o]->getrow();*/
		if (aaaaaaaaa == false)
			break;
		i = 1;

		while (this->matrix[i]->getRow() <= currentRow )
			i++;
		begin = i;
		currentRow = this->matrix[i]->getRow();
		j = 1;
		currentCol = n->matrix[j]->getRow();
	}//end of first while

	return new Matrix_OF(ans);
}