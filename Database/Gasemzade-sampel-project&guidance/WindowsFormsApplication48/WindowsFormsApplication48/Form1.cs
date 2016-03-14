using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace WindowsFormsApplication48
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MyData md = new MyData();
            md.strsql = "select city,count(*) as Tedad from s group by(city) ";
          //  md.strcon = "server=(local);database=company;integrated security=true";
            dataGridView1.DataSource = md.ShowData().DefaultView;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MyData md = new MyData();
            md.strsql = "insert into s values('"+textBox1.Text+"','"+textBox2.Text+"',"+textBox3.Text+",'"+textBox4.Text+"')";
          //  md.strcon = "server=(local);database=company;integrated security=true";
            md.ManData();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            MyData md = new MyData();
            md.strsql = "delete from s where s#='" + textBox1.Text + "'";
           // md.strcon = "server=(local);database=company;integrated security=true";
            md.ManData();

        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            textBox1.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
            textBox2.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            textBox3.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
            textBox4.Text = dataGridView1.CurrentRow.Cells[3].Value.ToString();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            MyData md = new MyData();
            md.strsql = "update s set s#='" + textBox1.Text + "',sname='" + textBox2.Text + "',status=" + textBox3.Text + ",city='" + textBox4.Text + "' where s#='" + dataGridView1.CurrentRow.Cells[0].Value.ToString() + "'";
            //md.strcon = "server=(local);database=company;integrated security=true";
            md.ManData();
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            MyData md = new MyData();
            md.strsql = "select * from s where s# like '"+textBox5.Text+"%'";
            //md.strcon = "server=(local);database=company;integrated security=true";
            dataGridView1.DataSource = md.ShowData().DefaultView;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            SqlConnection con1 = new SqlConnection("server=(local);database=company;integrated security=true");
            con1.Open();
      SqlCommand c1=new SqlCommand();
            c1.CommandText="select count(*) from s";
            c1.Connection=con1;
            object x= c1.ExecuteScalar();
            this.Text=x.ToString()+"تعدا رکوردهای موجود:";
            con1.Close();
        }
    }
}
