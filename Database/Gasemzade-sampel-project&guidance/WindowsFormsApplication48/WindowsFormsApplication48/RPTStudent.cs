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
    public partial class RPTStudent : Form
    {
        public RPTStudent()
        {
            InitializeComponent();
        }

        private void RPTStudent_Load(object sender, EventArgs e)
        {

            CrystalReport1 cr1 = new CrystalReport1();
            crystalReportViewer1.ReportSource = cr1;
        }

        private void button1_Click(object sender, EventArgs e)
        {
           SqlConnection con1 = new SqlConnection(ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString);
            con1.Open();
            SqlDataAdapter da = new SqlDataAdapter("select * from student where stno='"+textBox1.Text+"'", con1);
            DataTable dt = new DataTable();
            da.Fill(dt);
            con1.Close();
            CrystalReport1 cr1 = new CrystalReport1();
            cr1.SetDataSource(dt.DefaultView);
            crystalReportViewer1.ReportSource = cr1;
           

        }
    }
}
