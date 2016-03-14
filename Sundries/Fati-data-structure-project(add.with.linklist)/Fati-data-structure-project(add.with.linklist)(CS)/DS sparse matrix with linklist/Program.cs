using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace ds_sparse_with_linklist
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("First Matrix");

            int row, col, element;
            string s = Console.ReadLine();
            string[] ss = s.Split(' ');
            row = int.Parse(ss[0]);
            col = int.Parse(ss[1]);
            element = int.Parse(ss[2]);

            int headcount;
            
            if (row >= col)
                headcount = row;
            else
                headcount = col;

            linkList sparse1 = new linkList(row, col);

            sparse1.createhead(headcount);

            for (int i = 0; i < element; i++)
            {
                int r, c, e;
                string b = Console.ReadLine();
                string[] bb = b.Split(' ');
                
                r = int.Parse(bb[0]);
                c = int.Parse(bb[1]);
                e = int.Parse(bb[2]);
                node p = new node(r, c, e);
                
                sparse1.Biuldlinklist(p);
            }

            sparse1.printLinkList(row, col);

            ///////////////////////// second input //////////////////////////
            Console.WriteLine("Second Matrix");

            s = Console.ReadLine();
            ss = s.Split(' ');
            row = int.Parse(ss[0]);
            col = int.Parse(ss[1]);
            element = int.Parse(ss[2]);

            if (row >= col)
                headcount = row;
            else
                headcount = col;

            linkList sparse2 = new linkList(row, col);

            sparse2.createhead(headcount);

            for (int i = 0; i < element; i++)
            {
                int r, c, e;
                string b = Console.ReadLine();
                string[] bb = b.Split(' ');

                r = int.Parse(bb[0]);
                c = int.Parse(bb[1]);
                e = int.Parse(bb[2]);
                node p = new node(r, c, e);

                sparse2.Biuldlinklist(p);
            }

            Console.WriteLine("---");

            sparse2.printLinkList(row, col);

            Console.WriteLine("Sum of Matrix1 and Matrix2");

            linkList sum = new linkList();
            sum = sum.add(sparse1, sparse2);

            sum.printLinkList(row, col);

            Console.ReadKey();
        }
    }


    public class node
    {

        public node next;
        public node down;
        public int row;
        public int col;
        public int data;

        public node(int ro, int co, int x)
        {
            this.row = ro;
            this.col = co;
            this.data = x;
            next = null;
            down = null;
        }

        public node()
        {
            down = null;
            next = null;
        }
    }

    public class linkList
    {
        List<node> head = new List<node>();

        node[] cols;                             // baraye negah dashtane akharin ozve hameye sotonha->
        public int col;                          // ke inkar baraye link dadan az akharin ozve->
        public int row;                          // soton be node jadide haman soton.
        
        public linkList(){}

        public linkList(int row, int col)
        {
            this.col = col;
            this.row = row;
            cols = new node[col];                // be tedade soton ha new mikonim
        }

        public void createhead(int headcount)
        {
            for (int i = 0; i < headcount; i++)  // dar avale kar hameye->
            {                                    // head haye matrix ra misazim->
                node q = new node();
                head.Add(q);
            } 
        }

        public void Biuldlinklist(node p)        // tabe e sakhte linklist->
        {                                        // done done node haro az vorodi migirim va midim be in tab

            node checker = head[p.row];          // node checker nodeiye ke to satre morede->
                                                 // nazar ke haman row ye node p mas mire jelo->  
                                                 // havagt cheker.next null bod next e on->
                                                 // khonaro vasl mikone be node jadid yani p
            while (checker.next != null)
            {
                checker = checker.next;
            }
            checker.next = p;                    // .



            if (head[p.col].down == null)        // dar in gesmat miyayim down head haro va->
            {                                    // down node hamono be ham vasl mikonim->
                head[p.col].down = p;
                cols[p.col] = p;                 // chejori -> aval az hame miyayim to head ro->
            }                                    // mibinim age down on heade on soton null bod in yani hich-> 
            else                                 // nodi az gabl to on soton nis pas down on heade soton ro midim->
            {                                    // be in node jadide haman(p) ke az vordi gereftim->
                cols[p.col].down = p;            // va on (p) ro dar khoneye [p.col] arrayeye cols mizarim->
                cols[p.col] = p;                 // ke dafeye bad bedonim ye nodi to on soton has ta vagti->
            }                                    // ke mikhayim down haro vasl konim bedonim ke akharin ozve->
        }                                        // on soton kodom node ke fagat down e hamon soton ro vasl konim behesh.

        public void printLinkList(int r, int c)
        {
            for (int i = 0; i < r; i++)
            {
                string s = "head next " + i + " : ";
                node q = head[i].next;
                if (q == null)
                    s += "null";
                else
                {
                    while (q != null)
                    {
                        s += q.row + "," + q.col + "," + q.data;
                        if (q.next != null)
                            s += " - ";
                        q = q.next;
                    }
                }
                Console.WriteLine(s);
            }

            Console.WriteLine("---------------");

            for (int i = 0; i < c; i++)
            {
                string s = "head down " + i + " : ";
                node q = head[i].down;
                if (q == null)
                    s += "null";
                else
                {
                    while (q != null)
                    {
                        s += q.row + "," + q.col + "," + q.data;
                        if (q.down != null)
                            s += " - ";
                        q = q.down;
                    }
                }
                Console.WriteLine(s);
            }
        }

        public linkList add(linkList l1, linkList l2)
        {
            linkList sum = new linkList(l1.row, l1.col);
            sum.createhead(l1.head.Count);

            node a;
            node b;
            int headcounter = 0;                          // baraye heade hardo linklist 

            while (headcounter < l1.head.Count)
            {
                a = l1.head[headcounter].next;
                b = l2.head[headcounter].next;
                while (a != null && b != null)
                {
                    if (a.col == b.col)
                    {
                        node q = new node(a.row, a.col, a.data + b.data);
                        sum.Biuldlinklist(q);
                        a = a.next;
                        b = b.next;
                    }
                    else if (a.col < b.col)
                    {
                        node q = new node(a.row, a.col, a.data);
                        sum.Biuldlinklist(q);
                        a = a.next;
                    }
                    else if (a.col > b.col)
                    {
                        node q = new node(b.row, b.col, b.data);
                        sum.Biuldlinklist(q);
                        b = b.next;
                    }
                }

                while (a != null)
                {
                    node q = new node(a.row, a.col, a.data);
                    sum.Biuldlinklist(q);
                    a = a.next;
                }

                while (b != null)
                {
                    node q = new node(b.row, b.col, b.data);
                    sum.Biuldlinklist(q);
                    b = b.next;
                }

                headcounter++;
            }
            return sum;
        }
    }

}