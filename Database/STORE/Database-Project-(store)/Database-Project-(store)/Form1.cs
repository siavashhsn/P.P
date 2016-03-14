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

namespace Database_Project__store_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            storeID_textBox.Text = "1";
            branchID_textBox.Text = "1";
            username_TextBox.Text = "علی";
            password_Textbox.Text = "1";
        }

        private void exit_Btn_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void login_Btn_Click(object sender, EventArgs e)
        {
            SqlConnection con1 = new SqlConnection("server=(local);database=STORE;integrated security=true");
            con1.Open();
            
            SqlCommand c1 = new SqlCommand();
            c1.CommandText = "select * from employee,branch where employee.workForBranch=branch.branchID and employeeID='" + password_Textbox.Text + "' and firstname='" + username_TextBox.Text + "' and branchID='" + branchID_textBox.Text + "' and storeID='" + storeID_textBox.Text + "';";
            //c1.CommandText = "select * from employee where employeeID='" + password_Textbox.Text + "' and firstname='" + username_TextBox.Text +
            //    "' and workForBranch in(select branchID from branch where branchID='" + branchID_textBox.Text + "' and storeID='" + storeID_textBox.Text + "')";
            c1.Connection = con1;
            SqlDataReader dr = c1.ExecuteReader();
            object[] x = new object[11];
            if(dr.Read())
            {
                dr.GetValues(x);
                MainForm form = new MainForm();
                if (x[4].ToString() == "مدير")
                    form.ismanger = true;
                else
                    form.ismanger = false;
                form.personBranch = x[6].ToString();
                form.personStore = x[10].ToString();
                form.personID = x[0].ToString();
                form.FormBorderStyle = FormBorderStyle.FixedSingle;
                form.ShowDialog();
            }
           
            con1.Close();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }
    }
}
