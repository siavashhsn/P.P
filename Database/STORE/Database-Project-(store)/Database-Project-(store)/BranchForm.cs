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
    public partial class BranchForm : Form
    {
        public BranchForm()
        {
            InitializeComponent();
        }

        public bool ismanager;
        public string personStore, presonBranch;

        public void showAllbranch()
        {
            myData md = new myData();
            md.strsql = "select * from branch";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        public void showError()
        {
            if (branchID_textBox.Text == "")
                MessageBox.Show("کلید اصلی مقدار ندارد");
        }

        public void emptyTheTextBoxs()
        {
            branchID_textBox.Text = "";
            branchCountry_textBox.Text = "";
            branchCity_textBox.Text = "";
            branchAvenue_textBox.Text = "";
            branchStoreID_textBox.Text = "";
        }

        private void BranchForm_Load(object sender, EventArgs e)
        {
            showAllbranch();
        }

        private void branchSearch_textBox_TextChanged(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "select * from branch where branchID like'" + branchSearch_textBox.Text + "%'";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void branchInsert_Btn_Click(object sender, EventArgs e)
        {
            if (ismanager == true)
            {
                showError();
                myData md = new myData();
                md.strsql = "insert into branch values('" +
                    branchID_textBox.Text + "','" +
                    branchCountry_textBox.Text + "','" +
                    branchCity_textBox.Text + "','" +
                    branchAvenue_textBox.Text + "','" +
                    branchStoreID_textBox.Text + "')";
                md.manData();
                showAllbranch();
            }
            else
                MessageBox.Show("شما اجازه ی دسترسی ندارید");
            emptyTheTextBoxs();
        }

        private void branchDelete_Btn_Click(object sender, EventArgs e)
        {
            if (ismanager == true)
            {
                myData md = new myData();
                md.strsql = "delete from branch where branchID='" + branchID_textBox.Text + "'";
                md.manData();
                showAllbranch();
            }
            else
                MessageBox.Show("شما اجازه ی دسترسی ندارید");
            emptyTheTextBoxs();
        }

        private void branchEdit_Btn_Click(object sender, EventArgs e)
        {
            if (ismanager == true)
            {
                myData md = new myData();
                md.strsql = "update branch set country='" +
                    branchCountry_textBox.Text + "', city='" +
                    branchCity_textBox.Text + "', avenue='" +
                    branchAvenue_textBox.Text + "', storeID='" +
                    branchStoreID_textBox.Text + "' where branchID='" +
                    dataGridView1.CurrentRow.Cells[0].Value.ToString() + "'";
                md.manData();
                showAllbranch();
            }
            else
                MessageBox.Show("شما اجازه ی دسترسی ندارید");
            emptyTheTextBoxs();
        }

        private void branchSearch_Btn_Click(object sender, EventArgs e)
        {
            SqlConnection con1 = new SqlConnection();
            con1.ConnectionString = ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString;
            con1.Open();
            SqlCommand c1 = new SqlCommand();
            c1.CommandText = "select * from branch where branchID='" + branchSearch_textBox.Text + "'";
            c1.Connection = con1;
            SqlDataReader dr = c1.ExecuteReader();

            object[] x = new object[8];
            if (dr.Read())
            {
                dr.GetValues(x);
                branchID_textBox.Text = x[0].ToString();
                branchCountry_textBox.Text = x[1].ToString();
                branchCity_textBox.Text = x[2].ToString();
                branchAvenue_textBox.Text = x[3].ToString();
                branchStoreID_textBox.Text = x[4].ToString();
            }

            con1.Close();
            branchSearch_textBox.Text = "";
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            branchID_textBox.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
            branchCountry_textBox.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            branchCity_textBox.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
            branchAvenue_textBox.Text = dataGridView1.CurrentRow.Cells[3].Value.ToString();
            branchStoreID_textBox.Text = dataGridView1.CurrentRow.Cells[4].Value.ToString();
        }

        private void searchStoreBranch_Btn_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "exec branchP1 '" + textBox1.Text + "'";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "delete from branchV1 where branchID='" + textBox2.Text + "' and storeID='" + textBox3.Text + "'";
            md.manData();
            showAllbranch();
        }
    }
}
