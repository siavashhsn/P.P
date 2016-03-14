using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication48
{
    public partial class _ٍEditStudent : Form
    {
        public _ٍEditStudent()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MyData md = new MyData();
           
            md.strsql = "update Student set Stno=N'" + textBox1.Text + "',Stname=N'" + textBox2.Text +
            "' StFamily=N'" + textBox3.Text +",Stfield=N'" + textBox4.Text + "' where Stno=N'" +
            dataGridView1.CurrentRow.Cells[0].Value.ToString() + "'";



            md.ManData();
        }
    }
}
