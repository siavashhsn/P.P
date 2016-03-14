using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Configuration;

namespace WindowsFormsApplication48
{
    public partial class SearchStudent : Form
    {
        public SearchStudent()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            SqlConnection con1 = new SqlConnection(); ;
            con1.ConnectionString = ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString;
            con1.Open();
            SqlDataAdapter da = new SqlDataAdapter();
            da.SelectCommand = new SqlCommand();
            da.SelectCommand.Connection = con1;
            da.SelectCommand.CommandType = CommandType.StoredProcedure;
            da.SelectCommand.CommandText = "p";
            da.SelectCommand.Parameters.Add(new SqlParameter("@x", SqlDbType.VarChar));
            da.SelectCommand.Parameters["@x"].Value = textBox1.Text;
            DataTable dt = new DataTable();
            da.Fill(dt);
            dataGridView1.DataSource= dt.DefaultView;
            con1.Close();
        }

        private void SearchStudent_Load(object sender, EventArgs e)
        {
            MyData md = new MyData();
            md.strsql = "select * from student";
            dataGridView1.DataSource = md.ShowData().DefaultView;
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            MyData md = new MyData();
            md.strsql = "select * from student where stno like '" + textBox5.Text + "%'";
            dataGridView1.DataSource = md.ShowData().DefaultView;
        }
    }
}
