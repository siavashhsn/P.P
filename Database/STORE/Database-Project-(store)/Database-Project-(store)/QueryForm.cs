using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Database_Project__store_
{
    public partial class QueryForm : Form
    {
        public QueryForm()
        {
            InitializeComponent();
        }

        myData md = new myData();
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            md.strsql = "select * from employee where employeeID in(select employeeID from checkout where checkoutPrice>300)";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            md.strsql = "select city,count(*)  from branch group by(city) having count(*)>2";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            md.strsql = "select firstname,lastname from Employee where salary=(select salary from Employee where _type='مدیر')";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            md.strsql = "select * from checkout where checkoutPrice>(select AVG(checkoutPrice) from checkout) and employeeID in(select employeeID from employee where firstname='علی')";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            md.strsql = "select sname from _store where storeID in(select storeID from branch where branchID in(select workForBranch from employee where firstname='علی'))";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            md.strsql = "select * from _store where storeID in(select storeID from branch where branchID in(select branchID from checkout  where checkoutPrice>(select AVG(checkoutPrice) from checkout)))";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            md.strsql = "select * from checkout where customerID in(select customerID from customer where datejoined='1.1.1' and branchID in(select branchID from branch where city='ارومیه'))";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            md.strsql = "select * from branch where branchID in(select workForBranch from employee where firstname like 'ع%') and city like 'ا%'";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            md.strsql = "select * from customer where customerID in(select customerID from checkout where employeeID in(select employeeID from employee where firstname='علی'))";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            md.strsql = "update checkout set checkoutPrice=checkoutPrice - 100 where customerID='1' and branchID in(select branchID from branch where city='اومیه') and checkoutPrice > 1000";
            dataGridView1.DataSource = md.showData().DefaultView;
        }

        private void QueryForm_Load(object sender, EventArgs e)
        {

        }


    }
}
