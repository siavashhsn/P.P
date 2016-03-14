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
using System.IO;
using FastReport;

namespace Database_Project__store_
{
    public partial class BranchInventoryForm : Form
    {

        public bool ismanager;
        public string personStore, personBranch;
        public BranchInventoryForm()
        {
            InitializeComponent();
            inventoryBranchID_textBox.Text = personBranch; 
        }        

        public void showAllItem()
        {
            myData md = new myData();
            md.strsql = "select * from branchInventory";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        public void showAllItem_FromItemsTable()
        {
            myData md = new myData();
            md.strsql = "select * from items";
            dataGridView2.DataSource = md.showData().DefaultView;
        }

        public void showError()
        {
            if (inventoryItemID_textBox.Text == "")
                MessageBox.Show("شماره محصول وارد نشده است");
        }

        public void emptyTheTextBoxs()
        {
            inventoryItemID_textBox.Text = "";
            inventoryQty_textBox.Text = "";
        }

        private void BranchInventoryForm_Load(object sender, EventArgs e)
        {
            inventoryBranchID_textBox.Text = personBranch;
            showAllItem();
            showAllItem_FromItemsTable();
        }

        private void inventoryInsert_Btn_Click(object sender, EventArgs e)
        {
            showError();
            myData md = new myData();
            md.strsql = "insert into branchInventory values('" +
                inventoryBranchID_textBox.Text + "','" +
                inventoryItemID_textBox.Text + "'," +
                inventoryQty_textBox.Text + ")";
            md.manData();
            showAllItem();
            emptyTheTextBoxs();
        }

        private void inventoryDelete_Btn_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "delete from branchInventory where branchID='" +
                inventoryBranchID_textBox.Text + "' and itemID='" +
                inventoryItemID_textBox .Text + "'";
            md.manData();
            showAllItem();
            emptyTheTextBoxs();
        }

        private void inventoryEdit_Btn_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "update branchInventory set qty=" +
                inventoryQty_textBox.Text + " where BranchID='" +
                dataGridView1.CurrentRow.Cells[0].Value.ToString() + "' and ItemID='" +
                dataGridView1.CurrentRow.Cells[1].Value.ToString() + "'";
            md.manData();
            showAllItem();
            emptyTheTextBoxs();
        }

        private void inventorySearch_Btn_Click(object sender, EventArgs e)
        {
            SqlConnection con1 = new SqlConnection();
            con1.ConnectionString = ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString;
            con1.Open();
            SqlCommand c1 = new SqlCommand();
            c1.CommandText = "select * from branchInventory where itemID='" + inventorySearch_textBox.Text +
                "' and branchID='" + inventoryBranchID_textBox.Text + "'";
            c1.Connection = con1;
            SqlDataReader dr = c1.ExecuteReader();

            object[] x = new object[3];

            if (dr.Read())
            {
                dr.GetValues(x);
                inventoryItemID_textBox.Text = x[1].ToString();
                inventoryQty_textBox.Text = x[2].ToString();
            }

            con1.Close();
            inventorySearch_textBox.Text = "";
        }

        private void inventorySearch_textBox_TextChanged(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "select * from branchInventory where itemID like'" +
                inventorySearch_textBox.Text + "%' and branchID='" +
                inventoryBranchID_textBox.Text + "'";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            inventoryItemID_textBox.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            inventoryQty_textBox.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView2_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            inventoryItemID_textBox.Text = dataGridView2.CurrentRow.Cells[0].Value.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "select * from inventoryV1 where storeID='" + personStore + "'";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "exec inventoryP1 '" + personBranch + "'";
            md.manData();
            showAllItem();
        }

        private void report_Btn_Click(object sender, EventArgs e)
        {
            Report r = new Report();
            r.Load(Directory.GetCurrentDirectory()+"\\branchInventoryReport.frx");
            r.Show();
        }
    }
}
