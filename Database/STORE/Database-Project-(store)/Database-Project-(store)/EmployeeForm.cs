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
    public partial class EmployeeForm : Form
    {
        public EmployeeForm()
        {
            InitializeComponent();
            label4.Text = "ثبت فقط شماره و نام و حقوق کارمندان";
        }
        public bool ismanager;
        public string personStore, presonBranch;
        public void showAllEmp()
        {
            myData md = new myData();
            md.strsql = "select * from employee";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        public void showError()
        {
            if (empID_Textbox.Text == "")
                MessageBox.Show("کلید اصلی مقدار ندارد");
        }

        private void EmployeeForm_Load(object sender, EventArgs e)
        {
            showAllEmp();
        }

        public void emptyTheTextBoxs()
        {
            empID_Textbox.Text = "";
            empFname_Textbox.Text = "";
            empLname_Textbox.Text = "";
            empSalary_Textbox.Text = "";
            empType_textbox.Text = "";
            empWorksFor_Textbox.Text = "";
        }

        private void empInsert_Btn_Click(object sender, EventArgs e)
        {
            if (ismanager == true)
            {
                showError();
                myData md = new myData();
                md.strsql = "insert into employee values('" +
                    empID_Textbox.Text + "','" +
                    empFname_Textbox.Text + "','" +
                    empLname_Textbox.Text + "','" +
                    empSalary_Textbox.Text + "','" +
                    empType_textbox.Text + "','" +
                    empWorksFor_Textbox.Text + "')";
                md.manData();
                showAllEmp();
            }
            else 
                MessageBox.Show("شما اجازه ی دسترسی ندارید");
            emptyTheTextBoxs();
        }

        private void empDelete_Btn_Click(object sender, EventArgs e)
        {
            if (ismanager == true)
            {
                myData md = new myData();
                md.strsql = "delete from employee where employeeID='" + empID_Textbox.Text + "'";
                md.manData();
                showAllEmp();
            }
            else
                MessageBox.Show("شما اجازه ی دسترسی ندارید");
            emptyTheTextBoxs();
        }

        private void empSearch_Btn_Click(object sender, EventArgs e)
        {
            SqlConnection con1 =  new SqlConnection();
            con1.ConnectionString = ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString;
            con1.Open();
            SqlCommand c1 = new SqlCommand();
            c1.CommandText = "select * from employee where employeeID='" + empSearchTextBox.Text + "'";
            c1.Connection = con1;
            SqlDataReader dr = c1.ExecuteReader();

            object[] x = new object[8];
            if(dr.Read())
            {
                dr.GetValues(x);
                empID_Textbox.Text = x[0].ToString();
                empFname_Textbox.Text = x[1].ToString();
                empLname_Textbox.Text = x[2].ToString();
                empSalary_Textbox.Text = x[3].ToString();
                empType_textbox.Text = x[4].ToString();
                empWorksFor_Textbox.Text = x[5].ToString();
            }
            
            con1.Close();
            empSearchTextBox.Text = "";
        }

        private void empSearchTextBox_TextChanged(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "select * from employee where employeeID like'" + empSearchTextBox.Text + "%'";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void empEdit_Btn_Click(object sender, EventArgs e)
        {
            if (ismanager == true)
            {
                myData md = new myData();
                md.strsql = "update employee set  firstname='" +
                    empFname_Textbox.Text + "', lastname='" +
                    empLname_Textbox.Text + "', salary='" +
                    empSalary_Textbox.Text + "', _type='" +
                    empType_textbox.Text + "', workForBranch='" +
                    empWorksFor_Textbox.Text + "' where employeeID='" +
                    dataGridView1.CurrentRow.Cells[0].Value.ToString() + "'";
                md.manData();
                showAllEmp();
            }
            else
                MessageBox.Show("شما اجازه ی دسترسی ندارید");
            emptyTheTextBoxs();
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            empID_Textbox.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
            empFname_Textbox.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            empLname_Textbox.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
            empSalary_Textbox.Text = dataGridView1.CurrentRow.Cells[3].Value.ToString();
            empType_textbox.Text = dataGridView1.CurrentRow.Cells[4].Value.ToString();
            empWorksFor_Textbox.Text = dataGridView1.CurrentRow.Cells[5].Value.ToString();
        }

        private void showAllEmp_textbox_Click(object sender, EventArgs e)
        {
            showAllEmp();
        }

        private void insertAsView1_Btn_Click(object sender, EventArgs e)
        {
            if (ismanager == true)
            {
                showError();
                myData md = new myData();
                md.strsql = "insert into empView values('" + empID_Textbox.Text + "','" + empFname_Textbox.Text + "','" + empSalary_Textbox.Text + "')";
                md.manData();
                showAllEmp();
            }
            else
                MessageBox.Show("شما اجازه ی دسترسی ندارید");
            emptyTheTextBoxs();
        }

        private void showBranchManager_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "exec empP1";
            dataGridView1.DataSource = md.showData().DefaultView;
            
        }
        private void insertWithProcedure_Click(object sender, EventArgs e)
        {
            if (ismanager == true)
            {
                myData md = new myData();
                md.strsql = "exec empP2 '" +
                    empID_Textbox.Text + "','" +
                    empFname_Textbox.Text + "','" +
                    empLname_Textbox.Text + "','" +
                    empSalary_Textbox.Text + "','" +
                    empType_textbox.Text + "','" +
                    empWorksFor_Textbox.Text + "'";
                md.manData();
                showAllEmp();
            }
            else
                MessageBox.Show("شما اجازه ی دسترسی ندارید");
            emptyTheTextBoxs();
        }
    }
}
