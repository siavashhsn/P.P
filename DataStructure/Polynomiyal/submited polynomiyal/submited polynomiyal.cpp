using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace polynomial
{
	class Program
	{
		static void Main(string[] args)
		{
			string s = "";

			string[] splite;

			s = Console.ReadLine();
			splite = s.Split(' ');

			Polynomial a = new Polynomial();
			Polynomial b = new Polynomial();


                        /*//if (int.Parse(splite[0]) != 0 && int.Parse(splite[1]) == 0)
			//{
			//    a = new Polynomial(int.Parse(splite[0]));
			//    b = new Polynomial(1);
			//    for (int i = 0; i < a.Terms; i++)
			//    {
			//        s = Console.ReadLine();
			//        splite = s.Split(' ');
			//        a.setterm(double.Parse(splite[0]), int.Parse(splite[1]), i);
			//    }
			//    b.setterm(0, 0, 0);
			//}
			//else if (int.Parse(splite[0]) == 0 && int.Parse(splite[1]) != 0)
			//{

			//    a = new Polynomial(1);
			//    b = new Polynomial(int.Parse(splite[1]));
			//    a.setterm(0, 0, 0);
			//    for (int i = 0; i < b.Terms; i++)
			//    {
			//        s = Console.ReadLine();
			//        splite = s.Split(' ');
			//        b.setterm(double.Parse(splite[0]), int.Parse(splite[1]), i);
			//    }
			//}
			//else if (int.Parse(splite[0]) == 0 && int.Parse(splite[1]) == 0)
			//{
			//    a = new Polynomial(1);
			//    b = new Polynomial(1);
			//    a.setterm(0, 0, 0);
			//    b.setterm(0, 0, 0);
			//}
			// else
                        //{*/
			a = new Polynomial(int.Parse(splite[0]));
			b = new Polynomial(int.Parse(splite[1]));
			for (int i = 0; i < a.Terms; i++)
			{
				s = Console.ReadLine();
				splite = s.Split(' ');
				a.setterm(double.Parse(splite[0]), int.Parse(splite[1]), i);
			}
			for (int i = 0; i < b.Terms; i++)
			{
				s = Console.ReadLine();
				splite = s.Split(' ');
				b.setterm(double.Parse(splite[0]), int.Parse(splite[1]), i);
			}
			//}


			Polynomial c = new Polynomial();

			string ss = Console.ReadLine();

			if (ss == "*")
				c = a.multiply(a, b);
			else
				c = a.sum1(a, b);

			Console.WriteLine(c.ToString());


		}
	}

	class Term
	{
		private double coef;
		private int exp;

		public Term(double c, int e)
		{
			coef = c;
			exp = e;
		}
		public Term()
		{
			coef = 0;
			exp = 0;
		}
		public double Coef
		{
			set{ coef = value; }
			get{ return coef; }
		}
		public int Exp
			{
				set
				{
					if (value > 0)
					exp = value;
					else
						exp = 0;
				}
				get{ return exp; }
			}

			public int Length{ get; set; }
	}

	class Polynomial
	{
		private Term[] termArray;
		private int terms;

		public Polynomial()
		{
		}
		public int Terms
		{
			get{ return terms; }
		}
		public Polynomial(int n)
			{
				termArray = new Term[n];
				terms = n;
			}
			public void setterm(double c, int e, int i)
			{
				termArray[i] = new Term(c, e);
			}
			public Term getterm(int i)
			{
				return termArray[i];
			}
			public Polynomial sum1(Polynomial a, Polynomial b)
			{
				int counter = 0, p = 0, q = 0;
				while (p < a.terms && q < b.terms)
				{
					if (a.termArray[p].Exp == b.termArray[q].Exp)
					{
						if (a.termArray[p].Coef + b.termArray[q].Coef != 0)
							counter++;
						p++;
						q++;

					}
					else if (a.termArray[p].Exp < b.termArray[q].Exp)
					{
						if (a.termArray[p].Coef != 0)
							counter++;
						p++;
					}
					else
					{
						if (b.termArray[q].Coef != 0)
							counter++;
						q++;
					}
				}

				while (p < a.terms)
				{
					if (a.termArray[p].Coef != 0)
						counter++;
					p++;
				}

				while (q < b.terms)
				{
					if (b.termArray[q].Coef != 0)
						counter++;
					q++;
				}

				Polynomial c = new Polynomial(counter);
				p = 0;
				q = 0;
				counter = 0;

				while (p < a.terms && q < b.terms)
				{
					if (a.termArray[p].Exp == b.termArray[q].Exp)
					{
						double x = a.termArray[p].Coef + b.termArray[q].Coef;
						if (x != 0)
						{
							c.setterm(x, a.termArray[p].Exp, counter);
							counter++;
						}
						p++;
						q++;
					}

					else if (a.termArray[p].Exp < b.termArray[q].Exp)
					{
						c.setterm(b.termArray[q].Coef, b.termArray[q].Exp, counter);
						counter++;
						q++;
					}
					else
					{
						c.setterm(a.termArray[p].Coef, a.termArray[p].Exp, counter);
						counter++;
						p++;
					}
				}

				while (p < a.terms)
				{
					if (a.termArray[p].Coef != 0)
					{
						c.setterm(a.termArray[p].Coef, a.termArray[p].Exp, counter);
						counter++;
					}
					p++;
				}
				while (q < b.terms)
				{
					if (b.termArray[q].Coef != 0)
					{
						c.setterm(b.termArray[q].Coef, b.termArray[q].Exp, counter);
						counter++;
					}
					q++;
				}
				c.terms = counter;
				return c;
			}

			public void sum2(ref Term[] a, ref Term[] b, ref Term[] c)
			{
				int p = 0, q = 0, h = 0;
				while (p<a.Length && b[q] != null)
				{
					if (a[p].Exp == b[q].Exp)
					{
						double x = a[p].Coef + b[q].Coef;
						if (x != 0)
						{
							c[h] = new Term();
							c[h].Coef = x;
							c[h].Exp = a[p].Exp;
							h++;
						}
						p++;
						q++;
					}
					else if (a[p].Exp > b[q].Exp)
					{
						c[h] = new Term();
						c[h].Coef = a[p].Coef;
						c[h].Exp = a[p].Exp;
						h++;
						p++;
					}
					else
					{
						c[h] = new Term();
						c[h].Coef = b[q].Coef;
						c[h].Exp = b[q].Exp;
						h++;
						q++;
					}
				}

				while (p<a.Length)
				{
					if (a[p].Coef != 0)
					{
						c[h] = new Term();
						c[h].Coef = a[p].Coef;
						c[h].Exp = a[p].Exp;
						h++;
					}
					p++;
				}
				while (b[q] != null)
				{
					if (b[q].Coef != 0)
					{
						c[h] = new Term();
						c[h].Coef = b[q].Coef;
						c[h].Exp = b[q].Exp;
						h++;
					}
					q++;
				}
			}

			public Polynomial multiply(Polynomial a, Polynomial b)
			{
				Polynomial x, y;
				Polynomial c;
				if (a.terms == 0 || b.terms == 0)
				{
					c = new Polynomial(0);
					return c;
				}

				if (a.termArray[0].Exp > b.termArray[0].Exp)
				{
					x = a;
					y = b;
				}
				else
				{
					x = b;
					y = a;
				}


				Term[] mlt = new Term[y.terms];
				Term[] sum = new Term[a.terms * b.terms + 2];
				Term[] temp = new Term[a.terms * b.terms + 2];

				int counter = 0;

				for (int i = 0; i < x.terms; i++)
				{
					for (int j = 0; j < y.terms; j++)
					{
						mlt[j] = new Term();
						mlt[j].Coef = x.getterm(i).Coef * y.getterm(j).Coef;
						mlt[j].Exp = x.getterm(i).Exp + y.getterm(j).Exp;
					}

					if (counter % 2 == 0)
						sum2(ref mlt, ref sum, ref temp);
					else
						sum2(ref mlt, ref temp, ref sum);
					counter++;
				}

				if (counter % 2 == 0)
				{
					counter = 0;
					for (int i = 0; i < sum.Length; i++)
					{
						if (sum[i] == null)
							break;
						else if (sum[i].Coef != 0)
							counter++;
					}
					c = new Polynomial(counter);
					for (int i = 0; i < counter; i++)
					{
						if (sum[i].Coef != 0)
							c.setterm(sum[i].Coef, sum[i].Exp, i);
					}
				}

				else
				{
					counter = 0;
					for (int i = 0; i < temp.Length; i++)
					{
						if (temp[i] == null)
							break;
						if (temp[i].Coef != 0)
							counter++;
					}
					c = new Polynomial(counter);
					for (int i = 0; i < counter; i++)
					{
						if (temp[i].Coef != 0)
							c.setterm(temp[i].Coef, temp[i].Exp, i);
					}
				}
				return c;
			}
			public override string ToString()
			{
				string s = "";
				if (this.terms == 0)
					return "0";
				s = this.terms + "\n";
				for (int i = 0; i < this.terms; i++)
				{
					s += this.getterm(i).Coef + " " + this.getterm(i).Exp;
					if (i < this.terms - 1)
						s += "\n";
				}
				return s;
			}
	}
}
