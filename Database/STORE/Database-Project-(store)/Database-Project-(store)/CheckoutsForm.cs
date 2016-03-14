using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Configuration;
using System.Data.SqlClient;
using System.IO;
using FastReport;

namespace Database_Project__store_
{
    public partial class CheckoutsForm : Form
    {
        public string itemC1, itemC2, itemC3;
        public string check1, check2, check3;
        public int checkID=1;

        public void deleteNullPriceChecks()
        {
            myData md = new myData();
            md.strsql = "delete from checkoutItems where checkoutID in(select checkoutID from checkout where checkoutPrice is NULL)";
            md.manData();
            md.strsql = "delete from checkout where checkoutPrice is NULL";
            md.manData();
        }
        public void _checkID()
        {
            SqlConnection con1 = new SqlConnection();
            con1.ConnectionString = ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString;
            con1.Open();
            SqlCommand c1 = new SqlCommand();
            c1.CommandText = "select * from checkout where branchID='" + personBranch + "' and checkoutID=(select MAX(checkoutID) from checkout)";
            c1.Connection = con1;
            SqlDataReader dr = c1.ExecuteReader();

            object[] x = new object[5];

            if (dr.Read())
            {
                dr.GetValues(x);
                checkID = int.Parse(x[0].ToString())+1;
            }
            con1.Close();
        }


        public CheckoutsForm()
        {
            InitializeComponent();
        }
        public bool ismanager;
        public string personStore, personBranch, personID;  

        public void showAllItem()
        {
            myData md = new myData();
            md.strsql = "select * from branchInventory where branchID='" + personBranch + "'";
            ItemdataGridView.DataSource = md.showData().DefaultView;
        }

        public void showAllcheckouts()
        {
            myData md = new myData();
            md.strsql = "select * from checkout where BranchID='" + personBranch + "'";
            dataGridView.DataSource = md.showData().DefaultView;
        }

        public void showAllCheckoutItems()
        {
            myData md = new myData();
            md.strsql = "select * from checkoutItems where checkoutID=" + checkID;
            checkoutItemdataGridView.DataSource = md.showData().DefaultView;
        }

        public void initializeInsert_ForCheckout()
        {
            myData md = new myData();
            md.strsql = "insert into checkout(checkoutID, employeeID ,branchID) values(" + checkID + ",'"+ personID + "','" + personBranch +"')";
            md.manData();
        }

        private void CheckoutsForm_Load(object sender, EventArgs e)
        {
            deleteNullPriceChecks();
            _checkID();
            chechoutID_textBox.Text = checkID.ToString();
            employeeID_textBox.Text = personID.ToString();
            branchID_textBox.Text = personBranch.ToString();
            deleteNullPriceChecks();
            initializeInsert_ForCheckout();
            showAllcheckouts();
            showAllItem();
            showAllcheckouts();
        }

        private void selectTheItem_Btn_Click(object sender, EventArgs e)
        {
            if (itemC1 == null)
                MessageBox.Show("محصول را انتخاب کنید");
            else if(qtyOfItem_textBox.Text == "")
                MessageBox.Show("مقدار محصول را انتخاب کنید");
            else if(int.Parse(qtyOfItem_textBox.Text) > int.Parse(itemC3))
                MessageBox.Show("مقدار محصول مورد تایید نیست");
            else
            {
                string itemprice="";
                SqlConnection con1 = new SqlConnection();
                con1.ConnectionString = ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString;
                con1.Open();
                SqlCommand c1 = new SqlCommand();
                c1.CommandText = "select * from items where itemID='" + itemC2 + "'";
                c1.Connection = con1;
                SqlDataReader dr = c1.ExecuteReader();

                object[] x = new object[3];

                if (dr.Read())
                {
                    dr.GetValues(x);
                    itemprice = x[2].ToString();
                }
                con1.Close();

                string p = ((Int64.Parse(qtyOfItem_textBox.Text)) * (Int64.Parse(itemprice))).ToString();

                myData md = new myData();
                md.strsql = "insert into checkoutItems values(" + checkID + ",'" + itemC2 + "'," + qtyOfItem_textBox.Text +"," + p + ")";
                md.manData();
                if (int.Parse(qtyOfItem_textBox.Text) - int.Parse(itemC3) == 0)
                {
                    md.strsql = "delete from branchInventory where BranchID='" +
                        personBranch + "' and ItemID='" +
                        itemC2 + "'";
                    md.manData();
                    showAllItem();
                }
                else
                {
                    md.strsql = "update branchInventory set qty=" +
                        (int.Parse(itemC3)-int.Parse(qtyOfItem_textBox.Text)).ToString() + " where BranchID='" +
                        personBranch + "' and ItemID='" +
                        itemC2 + "'";
                    md.manData();
                    showAllItem();
                }
                qtyOfItem_textBox.Text = "";
                showAllCheckoutItems();
            }
        }

        private void ItemdataGridView_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            itemC1 = ItemdataGridView.CurrentRow.Cells[0].Value.ToString();
            itemC2 = ItemdataGridView.CurrentRow.Cells[1].Value.ToString();
            itemC3 = ItemdataGridView.CurrentRow.Cells[2].Value.ToString();
        }

        private void checkInsert_Btn_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "update checkout set checkoutPrice=(select sum(price) from checkoutItems where checkoutID=" + checkID +
                "),customerID='" + customerID_textBox.Text + "' where checkoutID=" + checkID;
            md.manData();
            showAllcheckouts();
            _checkID();
            chechoutID_textBox.Text = checkID.ToString();
            customerID_textBox.Text = "";
            initializeInsert_ForCheckout();
        }   

        private void editTheQtyOfItem_Btn_Click(object sender, EventArgs e)
        {
            if (editQtyOfItem_textBox.Text == "")
                MessageBox.Show("جهت ویرایش, مقدار محصول را انتخاب کنید");
            else if (int.Parse(editQtyOfItem_textBox.Text) > int.Parse(itemC3))
                MessageBox.Show("مقدار محصول مورد تایید نیست");
            else
            {
                SqlConnection con1 = new SqlConnection();
                con1.ConnectionString = ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString;
                con1.Open();
                SqlCommand c1 = new SqlCommand();
                c1.CommandText = "select * from branchInventory where itemID='" + check2 +
                    "' and branchID='" + personBranch + "'";
                c1.Connection = con1;
                SqlDataReader dr = c1.ExecuteReader();

                object[] x = new object[3];

                if (dr.Read())
                {
                    dr.GetValues(x);
                    itemC3 = x[2].ToString();
                }
                con1.Close();

                string i = (int.Parse(check3) + int.Parse(itemC3)).ToString();

                myData md = new myData();
                md.strsql = "update branchInventory set qty=" + i + " where branchID='" + personBranch + "' and itemID='" + check2 + "'";
                md.manData();

                md.strsql = "update checkoutItems set qty=" +
                    editQtyOfItem_textBox.Text + " where checkoutID=" +
                    check1 + "and itemID='" + check2 + "'";
                md.manData();

                showAllCheckoutItems();
                
                if (int.Parse(editQtyOfItem_textBox.Text) - int.Parse(i) == 0)
                {
                    md.strsql = "delete from branchInventory where BranchID='" +
                        personBranch + "' and ItemID='" +
                        itemC2 + "'";
                    md.manData();
                    showAllItem();
                }
                else
                {
                    md.strsql = "update branchInventory set qty=" +
                        (int.Parse(i) - int.Parse(editQtyOfItem_textBox.Text)).ToString() + " where BranchID='" +
                        personBranch + "' and ItemID='" +
                        itemC2 + "'";
                    md.manData();
                    showAllItem();
                }
                editQtyOfItem_textBox.Text = "";
                showAllItem();
            }
        }

        private void checkoutItemdataGridView_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            check1 = checkoutItemdataGridView.CurrentRow.Cells[0].Value.ToString();
            check2 = checkoutItemdataGridView.CurrentRow.Cells[1].Value.ToString();
            check3 = checkoutItemdataGridView.CurrentRow.Cells[2].Value.ToString();
        }

        private void deleteTheItem_Btn_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "delete from checkoutItems where checkoutID=" + check1 + " and itemID='" + check2 + "'";
            checkoutItemdataGridView.DataSource = md.showData().DefaultView;
            showAllCheckoutItems();
        }

        private void checkDelete_Btn_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "delete from checkoutItems where checkoutID=" + chechoutID_textBox.Text;
            md.manData();
            md.strsql = "delete from checkout where checkoutID=" + chechoutID_textBox.Text;
            md.manData();
            showAllcheckouts();
        }

        private void checkEdit_Btn_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "update checkout set checkoutPrice=" + checkoutPrice_textBox.Text +
                ",customerID='" + customerID_textBox.Text + "' where checkoutID=" + chechoutID_textBox.Text;
            md.manData();
            showAllcheckouts();
        }

        private void checkSearch_textBox_TextChanged(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "select * from checkout where checkoutID like'" + checkSearch_textBox.Text + "%'";
            dataGridView.DataSource = md.showData().DefaultView;
        }

        private void dataGridView_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            chechoutID_textBox.Text = dataGridView.CurrentRow.Cells[0].Value.ToString();
            customerID_textBox.Text = dataGridView.CurrentRow.Cells[1].Value.ToString();
            employeeID_textBox.Text = dataGridView.CurrentRow.Cells[2].Value.ToString();
            branchID_textBox.Text = dataGridView.CurrentRow.Cells[3].Value.ToString();
            checkoutPrice_textBox.Text = dataGridView.CurrentRow.Cells[4].Value.ToString();
        }

        private void checkSearch_Btn_Click(object sender, EventArgs e)
        {

            myData md = new myData();
            md.strsql = "select * from checkout where checkoutID=" + checkSearch_textBox.Text + "";
            dataGridView.DataSource = md.showData().DefaultView;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "exec CP3";
            dataGridView.DataSource = md.showData().DefaultView;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "exec CP2";
            dataGridView.DataSource = md.showData().DefaultView;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "select * from CV1";
            dataGridView.DataSource = md.showData().DefaultView;
        }

        private void report_Btn_Click(object sender, EventArgs e)
        {
            deleteNullPriceChecks();
            Report r = new Report();
            r.Load(Directory.GetCurrentDirectory() + "\\checkoutReport.frx");
            r.Show();
        }
    }
}
