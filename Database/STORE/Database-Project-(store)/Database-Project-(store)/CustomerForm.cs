using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Configuration;

namespace Database_Project__store_
{
    public partial class CustomerForm : Form
    {
        public CustomerForm()
        {
            InitializeComponent();
        }

        public bool ismanager;
        public string personStore, presonBranch;

        public void showAllCus()
        {
            myData md = new myData();
            md.strsql = "select * from customer";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        public void showError()
        {
            if (cusID_textBox.Text == "")
                MessageBox.Show("کلید اصلی مقدار ندارد");
        }

        public void emptyTheTextBoxs()
        {
            cusID_textBox.Text = "";
            cusBranchID_textBox.Text = "";
            cusJoinedDate_textBox.Text = "";
        }
        private void CustomerForm_Load(object sender, EventArgs e)
        {
            showAllCus();
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void cusInsert_Btn_Click(object sender, EventArgs e)
        {
            showError();
            myData md = new myData();
            md.strsql = "insert into customer values('" +
                cusID_textBox.Text + "','" +
                cusBranchID_textBox.Text + "','" +
                cusJoinedDate_textBox.Text + "')";
            md.manData();
            showAllCus();
            emptyTheTextBoxs();
        }

        private void cusSearch_Btn_Click(object sender, EventArgs e)
        {
            SqlConnection con1 = new SqlConnection();
            con1.ConnectionString = ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString;
            con1.Open();
            SqlCommand c1 = new SqlCommand();
            c1.CommandText = "select * from customer where customerID='" + cusSearch_textBox.Text + "'";
            c1.Connection = con1;
            SqlDataReader dr = c1.ExecuteReader();

            object[] x = new object[3];

            if (dr.Read())
            {
                dr.GetValues(x);
                cusID_textBox.Text = x[0].ToString();
                cusBranchID_textBox.Text = x[1].ToString();
                cusJoinedDate_textBox.Text = x[2].ToString();
            }

            con1.Close();

            cusSearch_textBox.Text = "";
        }

        private void cusEdit_Btn_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "update customer set  customerID='" +
                cusID_textBox.Text + "', branchID='" +
                cusBranchID_textBox.Text + "', datejoined='" +
                cusJoinedDate_textBox.Text + "' where customerID='" +
                dataGridView1.CurrentRow.Cells[0].Value.ToString() + "'";
            md.manData();
            showAllCus();
            emptyTheTextBoxs();
        }

       

        private void cusDelete_Btn_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "delete from customer where customerID='" + cusID_textBox.Text + "'";
            md.manData();
            showAllCus();
            emptyTheTextBoxs();
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            cusID_textBox.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
            cusBranchID_textBox.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            cusJoinedDate_textBox.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
        }



        private void cusSearch_textBox_TextChanged(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "select * from customer where customerID like'" + cusSearch_textBox.Text + "%'";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void CustomerForm_Load_1(object sender, EventArgs e)
        {
            showAllCus();
        }
    }
}
