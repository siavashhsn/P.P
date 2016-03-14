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
    public partial class NewStudent : Form
    {
        public NewStudent()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlConnection con1 = new SqlConnection(); ;
            con1.ConnectionString = ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString;
            con1.Open();
            SqlCommand c1 = new SqlCommand();
            c1.CommandType = CommandType.StoredProcedure;
            c1.CommandText = "InsData";
            c1.Connection = con1;
            c1.Parameters.Add(new SqlParameter("@x", SqlDbType.NVarChar));
            c1.Parameters["@x"].Value = textBox1.Text;

            c1.Parameters.Add(new SqlParameter("@y", SqlDbType.NVarChar));
            c1.Parameters["@y"].Value = textBox1.Text;

            c1.Parameters.Add(new SqlParameter("@z", SqlDbType.NVarChar));
            c1.Parameters["@z"].Value = textBox1.Text;

            c1.Parameters.Add(new SqlParameter("@t", SqlDbType.NVarChar));
            c1.Parameters["@t"].Value = textBox1.Text;

            c1.ExecuteNonQuery();
            con1.Close();
        }

        private void NewStudent_Load(object sender, EventArgs e)
        {
            MyData md = new MyData();
            md.strsql = "select * from student";
            dataGridView1.DataSource = md.ShowData().DefaultView;
        }
    }
}
