using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Threading;
using System.Windows.Input;
using System.Text.RegularExpressions;
using System.Threading;
using System.IO;
using System.Windows.Forms;

namespace OS
{
    public partial class Form1 : Form
    {

        List<process> New = new List<process>();
        List<process> ready = new List<process>();
        process runing = new process();
        List<process> blocked = new List<process>();
        List<process> suspend = new List<process>();
        List<process> finished = new List<process>();
        public Form1()
        {
            InitializeComponent();
            for (int i = 0; i < 9; i++)
            {
                process p = new process();
                p.ID = id; p.name = "a"+i; p.state = "new";
                New.Add(p);
                add_tb.Text = "";
                if (ready.Count < 10)
                {
                    ready.Add(New.First());
                    New.RemoveAt(0);
                }
                id++;
            }
            UpdateListBox();

            DispatcherTimer t = new DispatcherTimer();
            t.Interval = new TimeSpan(0, 0, 1);
            t.Tick += t_Tick;
            t.Start();
        }



        void t_Tick(object sender, EventArgs e)
        {
            if (runing.name != null)
                runing.ttime++;
            foreach (var i in blocked)
                i.iowait--;
            foreach (var i in suspend)
                i.iowait--;

            if (runing.name != null)
            {
                process ppp = new process();
                ppp = runing;
                ppp.state = "ready";
                ready.Add(ppp);
            }

            if (ready.Count > 0)
            {
                Random r = new Random();
                int iotime = r.Next(1, 5);
                int ioproc = r.Next(0, ready.Count - 1);

                process p = new process();
                p = ready[ioproc];
                p.iowait = iotime;


                if (iotime > 2)
                {
                    p.state = "suspend";
                    suspend.Add(p);
                    ready.RemoveAt(ioproc);
                }
                else
                {
                    p.state = "blocked";
                    blocked.Add(p);
                    ready.RemoveAt(ioproc);
                }

                UpdateListBox();

                if (ready.Count > 0)
                {
                    runing = ready[0];
                    runing.state = "runing";
                    ready.RemoveAt(0);
                }
            }
            int bs = blocked.Count;
            int ss = suspend.Count;

            List<process> blocktemp = new List<process>();
            List<process> suspendtemp = new List<process>();
            List<process> newtemp = new List<process>();

            //blocked.Reverse();
            for (int i = bs - 1; i >= 0; i--)
            {
                if (ready.Count < 10)
                {
                    if (blocked[i].iowait <= 0)
                    {
                        process pp = new process();
                        pp = blocked[i];
                        pp.state = "ready";
                        ready.Add(pp);
                        //blocked.RemoveAt(i
                    }
                    else
                        blocktemp.Add(blocked[i]);
                }
                else
                    break;
            }
            blocked = blocktemp;

            //blocked.Reverse();

            //suspend.Reverse();
            for (int i = ss - 1; i >= 0; i--)
            {
                if (ready.Count < 10)
                {
                    if (suspend[i].iowait <= 3)
                    {
                        process pp = new process();
                        pp = suspend[i];
                        pp.state = "ready";
                        ready.Add(pp);
                        suspend.RemoveAt(i);
                    }
                    else
                        suspendtemp.Add(suspend[i]);
                }
                else
                    break;
            }
            suspend = suspendtemp;
            //suspend.Reverse();


            //New.Reverse();
            if (New.Count > 0)
            {
                if (ready.Count < 10)
                {
                    for (int j = New.Count - 1; j >= 0; j--)
                    {
                        if (ready.Count < 10)
                        {
                            New[j].state = "ready";
                            ready.Add(New[j]);
                        }
                        else
                            newtemp.Add(New[j]);
                    }
                }
            }
            New = newtemp;
            //New.Reverse();
            UpdateListBox();
        }
        static int id = 0;

        
        private void add_btn_Click(object sender, EventArgs e)
        {
            process p = new process();
            p.ID = id;
            p.name = add_tb.Text;
            p.state = "new";
            New.Add(p);
            add_tb.Text = "";
            if (ready.Count < 10)
            {
                ready.Add(New.First());
                New.RemoveAt(0);
            }
            id++;
            UpdateListBox();
           
            
        }
        private void end_btn_Click(object sender, EventArgs e)
        {
            if (end_tb.Text != "")
            {
                int _id = int.Parse(end_tb.Text);
                process p = new process();
                foreach (var i in New)
                    if (i.ID == _id)
                    {
                        p = i;
                        New.Remove(i);
                        break;
                    }
                foreach (var i in ready)
                    if (i.ID == _id)
                    {
                        p = i;
                        ready.Remove(i);
                        break;
                    }
                foreach (var i in suspend)
                    if (i.ID == _id)
                    {
                        p = i;
                        suspend.Remove(i);
                        break;
                    }
                foreach (var i in blocked)
                    if (i.ID == _id)
                    {
                        p = i;
                        blocked.Remove(i);
                        break;
                    }
                if (runing != null && runing.name != null && runing.ID == _id)
                {
                    p = runing;
                    runing = null;
                }
                if (p != null)
                {
                    p.state = "EXIT";
                    finished.Add(p);
                    string s = p.ID.ToString() + "    " + p.name + "    " + p.ttime + "  sec\n";
                    File.AppendAllText(Environment.CurrentDirectory + "\\log.txt", s);
                }
            }
            end_tb.Text = "";
            UpdateListBox();
        }

        private void UpdateListBox()
        {
            ready_lb.DataSource = null;
            ready_lb.DataSource = ready;
            ready_lb.SelectedIndex = -1;
            ready_lb.DisplayMember = "ID";
            
            runung_lb.Items.Clear();
            if(runing!=null && runing.name!=null)
                runung_lb.Items.Add(runing);
            runung_lb.SelectedIndex = -1;
            runung_lb.DisplayMember = "ID";
            
            blocked_lb.DataSource = null;
            blocked_lb.DataSource = blocked;
            blocked_lb.SelectedIndex = -1;
            blocked_lb.DisplayMember = "ID";

            suspend_lb.DataSource = null;
            suspend_lb.DataSource = suspend;
            suspend_lb.SelectedIndex = -1;
            suspend_lb.DisplayMember = "ID";

            finished_lb.DataSource = null;
            finished_lb.DataSource = finished;
            finished_lb.SelectedIndex = -1;
            finished_lb.DisplayMember = "ID";

            //info_lb.Items.Clear();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void info_lb_Click(object sender, EventArgs e)
        {
           
        }

        private void ready_lb_SelectedIndexChanged(object sender, EventArgs e)
        {
            //process p = ready_lb.SelectedItem as process;

            //if (p != null)
            //{
            //    int b = p.ID;
            //    int d = p.ttime;
            //    string c = p.name;
            //    ready_lb.ClearSelected();
            //    textBox1.Text = b.ToString() + "\n" + c + "\nready" + d.ToString();
            //}
            //    info_lb.Items.Clear();
            //    info_lb.Items.Add(b);
            //    info_lb.Items.Add(c);
            //    info_lb.Items.Add("ready");
            //    info_lb.Items.Add(d);
            //}


        }

        private void runung_lb_SelectedIndexChanged(object sender, EventArgs e)
        {
            //process p = runung_lb.SelectedItem as process;
            //if (p != null)
            //{
            //    info_lb.Items.Clear();
            //    info_lb.Items.Add(p.ID);
            //    info_lb.Items.Add(p.name);
            //    info_lb.Items.Add(p.state);
            //    info_lb.Items.Add(p.ttime);
            //}
        }

        private void blocked_lb_SelectedIndexChanged(object sender, EventArgs e)
        {
            //process p = blocked_lb.SelectedItem as process;
            //if (p != null)
            //{
            //    info_lb.Items.Clear();
            //    if (p.ID != null && p.name != "" && p.state != "" && p.ttime != null)
            //    {
            //        info_lb.Items.Add(p.ID);
            //        info_lb.Items.Add(p.name);
            //        info_lb.Items.Add(p.state);
            //        info_lb.Items.Add(p.ttime);
            //    }
            //}
        }

        private void suspend_lb_SelectedIndexChanged(object sender, EventArgs e)
        {
            //process p = suspend_lb.SelectedItem as process;
            //if (p != null)
            //{
            //    info_lb.Items.Clear();
            //    info_lb.Items.Add(p.ID);
            //    info_lb.Items.Add(p.name);
            //    info_lb.Items.Add(p.state);
            //    info_lb.Items.Add(p.ttime);
            //}
        }

        private void finished_lb_SelectedIndexChanged(object sender, EventArgs e)
        {
            //process p = finished_lb.SelectedItem as process;
            //if (p != null)
            //{
            //    info_lb.Items.Clear();
            //    info_lb.Items.Add(p.ID);
            //    info_lb.Items.Add(p.name);
            //    info_lb.Items.Add(p.state);
            //    info_lb.Items.Add(p.ttime);
            //}
        }

        private void ready_lb_Click(object sender, EventArgs e)
        {

            process p = ready_lb.SelectedItem as process;

            if (p != null)
            {
                int b = p.ID;
                int d = p.ttime;
                string c = p.name;
                ready_lb.ClearSelected();
                string s = "";
                s += b.ToString() + "\r\n" + c + "\r\nready\r\n" + d.ToString();
                textBox1.Text = s;
            }

            //process p = ready_lb.SelectedItem as process;

            //if (p != null)
            //{
            //    int b = p.ID;
            //    int d = p.ttime;
            //    string c = p.name;
            //    ready_lb.ClearSelected();

            //    info_lb.Items.Clear();
            //    info_lb.Items.Add(b);
            //    info_lb.Items.Add(c);
            //    info_lb.Items.Add("ready");
            //    info_lb.Items.Add(d);
            //}
        }

        private void runung_lb_Click(object sender, EventArgs e)
        {
            process p = runung_lb.SelectedItem as process;

            if (p != null)
            {
                int b = p.ID;
                int d = p.ttime;
                string c = p.name;
                runung_lb.ClearSelected();
                string s = "";
                s += b.ToString() + "\r\n" + c + "\r\nruning\r\n" + d.ToString();
                textBox1.Text = s;
            }
        }

        private void blocked_lb_Click(object sender, EventArgs e)
        {
            process p = blocked_lb.SelectedItem as process;

            if (p != null)
            {
                int b = p.ID;
                int d = p.ttime;
                string c = p.name;
                blocked_lb.ClearSelected();
                string s = "";
                s += b.ToString() + "\r\n" + c + "\r\nblocked\r\n" + d.ToString();
                textBox1.Text = s;
            }
        }

        private void suspend_lb_Click(object sender, EventArgs e)
        {
            process p = suspend_lb.SelectedItem as process;

            if (p != null)
            {
                int b = p.ID;
                int d = p.ttime;
                string c = p.name;
                suspend_lb.ClearSelected();
                string s = "";
                s += b.ToString() + "\r\n" + c + "\r\nsuspend\r\n" + d.ToString();
                textBox1.Text = s;
            }
        }

        private void finished_lb_Click(object sender, EventArgs e)
        {
            process p = finished_lb.SelectedItem as process;

            if (p != null)
            {
                int b = p.ID;
                int d = p.ttime;
                string c = p.name;
                finished_lb.ClearSelected();
                string s = "";
                s += b.ToString() + "\r\n" + c + "\r\nfinished\r\n" + d.ToString();
                textBox1.Text = s;
            }
        }


    }

    public class process
    {  
        public int ID { get; set; }
        public string name;
        public string state;
        public int ttime = 0;
        public int iowait = 0;
    }
}
