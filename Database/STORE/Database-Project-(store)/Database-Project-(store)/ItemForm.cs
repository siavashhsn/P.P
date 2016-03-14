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
    public partial class ItemForm : Form
    {
        public ItemForm()
        {
            InitializeComponent();
        }

        public void showAllItem()
        {
            myData md = new myData();
            md.strsql = "select * from items";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        public void showError()
        {
            if (itemID_textBox.Text == "")
                MessageBox.Show("کلید اصلی مقدار ندارد");
        }

        public void emptyTheTextBoxs()
        {
            itemID_textBox.Text = "";
            itemName_textBox.Text = "";
            itemPrice_textBox.Text = "";
        }

        private void ItemForm_Load(object sender, EventArgs e)
        {
            showAllItem();
        }

        private void itemInsert_Btn_Click(object sender, EventArgs e)
        {
            showError();
            myData md = new myData();
            md.strsql = "insert into items values('" +
                itemID_textBox.Text + "','" +
                itemName_textBox.Text + "'," +
                itemPrice_textBox.Text + ")";
            md.manData();
            showAllItem();
            emptyTheTextBoxs();
        }

        private void itemDelete_Btn_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "delete from items where itemID='" + itemID_textBox.Text + "'";
            md.manData();
            showAllItem();
            emptyTheTextBoxs();
        }

        private void itemEdit_Btn_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "update items set Iname='" +
                itemName_textBox.Text + "', price=" +
                itemPrice_textBox.Text + " where itemID='" +
                dataGridView1.CurrentRow.Cells[0].Value.ToString() + "'";
            md.manData();
            showAllItem();
            emptyTheTextBoxs();
        }

        private void itemSearch_Btn_Click(object sender, EventArgs e)
        {
            SqlConnection con1 = new SqlConnection();
            con1.ConnectionString = ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString;
            con1.Open();
            SqlCommand c1 = new SqlCommand();
            c1.CommandText = "select * from items where itemID='" + itemSearch_textBox.Text + "'";
            c1.Connection = con1;
            SqlDataReader dr = c1.ExecuteReader();

            object[] x = new object[3];

            if (dr.Read())
            {
                dr.GetValues(x);
                itemID_textBox.Text = x[0].ToString();
                itemName_textBox.Text = x[1].ToString();
                itemPrice_textBox.Text = x[2].ToString();
            }

            con1.Close();
            itemSearch_textBox.Text = "";
        }

        private void itemSearch_textBox_TextChanged(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "select * from items where itemID like'" + itemSearch_textBox.Text + "%'";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            itemID_textBox.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
            itemName_textBox.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            itemPrice_textBox.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "select count(itemID) from itemV1";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "exec itemP1 '" + textBox1.Text + "'";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "select * from items where itemID like'" + textBox1.Text + "%'";
            dataGridView1.DataSource = md.showData().DefaultView;
        }
    }
}
