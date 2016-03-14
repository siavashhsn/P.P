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
    public partial class StoreForm : Form
    {
        public StoreForm()
        {
            InitializeComponent();
        }
        public bool ismanager;
        public string personStore, presonBranch;

        public void showAllStore()
        {
            myData md = new myData();
            md.strsql = "select * from _store";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        public void showError()
        {
            if (storeID_textBox.Text == "")
                MessageBox.Show("کلید اصلی مقدار ندارد");
        }

        public void emptyTheTextBoxs()
        {
            storeID_textBox.Text = "";
            storeName_textBox.Text = "";
            storeBDate_textBox.Text = "";
        }
        private void StoreForm_Load(object sender, EventArgs e)
        {
            showAllStore();
        }

        private void storeInsert_Btn_Click(object sender, EventArgs e)
        {
            if (ismanager == true)
            {
                showError();
                myData md = new myData();
                md.strsql = "insert into _store values('" +
                    storeID_textBox.Text + "','" +
                    storeName_textBox.Text + "','" +
                    storeBDate_textBox.Text + "')";
                md.manData();
                showAllStore();
            }
            else
                MessageBox.Show("شما اجازه ی دسترسی ندارید");
            emptyTheTextBoxs();
        }

        private void storeDelete_Btn_Click(object sender, EventArgs e)
        {
            if (ismanager == true)
            {
                myData md = new myData();
                md.strsql = "delete from _store where storeID='" + storeID_textBox.Text + "'";
                md.manData();
                showAllStore();
            }
            else
                MessageBox.Show("شما اجازه ی دسترسی ندارید");
            emptyTheTextBoxs();
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            storeID_textBox.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
            storeName_textBox.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            storeBDate_textBox.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
        }

        private void storeEdit_Btn_Click(object sender, EventArgs e)
        {
            if (ismanager == true)
            {
                myData md = new myData();
                md.strsql = "update _store set storeID='" +
                    storeID_textBox.Text + "', sname='" +
                    storeName_textBox.Text + "', Bdate='" +
                    storeBDate_textBox.Text + "' where storeID='" +
                    dataGridView1.CurrentRow.Cells[0].Value.ToString() + "'";
                md.manData();
                showAllStore();
            }
            else
                MessageBox.Show("شما اجازه ی دسترسی ندارید");
            emptyTheTextBoxs();
        }

        private void storeSearch_Btn_Click(object sender, EventArgs e)
        {
            SqlConnection con1 = new SqlConnection();
            con1.ConnectionString = ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString;
            con1.Open();
            SqlCommand c1 = new SqlCommand();
            c1.CommandText = "select * from _store where storeID='" + storeSearch_textBox.Text + "'";
            c1.Connection = con1;
            SqlDataReader dr = c1.ExecuteReader();

            object[] x = new object[3];

            if (dr.Read())
            {
                dr.GetValues(x);
                storeID_textBox.Text = x[0].ToString();
                storeName_textBox.Text = x[1].ToString();
                storeBDate_textBox.Text = x[2].ToString();
            }

            con1.Close();
            storeSearch_textBox.Text = "";
        }

        private void storeSearch_textBox_TextChanged(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "select * from _store where storeID like'" + storeSearch_textBox.Text + "%'";
            dataGridView1.DataSource = md.showData().DefaultView;
        }
    }
}
