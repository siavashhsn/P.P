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
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        public bool ismanger;
        public string personStore, personBranch, personID;

        private void customerToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CustomerForm f = new CustomerForm();
            f.ismanager = this.ismanger;
            f.personStore = this.personStore;
            f.presonBranch = this.personBranch;
            f.FormBorderStyle = FormBorderStyle.FixedSingle;
            f.ShowDialog();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
        }

        private void employeeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            EmployeeForm f = new EmployeeForm();
            f.ismanager = this.ismanger;
            f.personStore = this.personStore;
            f.presonBranch = this.personBranch;
            f.FormBorderStyle = FormBorderStyle.FixedSingle;
            f.ShowDialog();
        }

        private void backupRestoreToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Backup_RestoreForm f;
            if (this.ismanger == true)
            {
                f = new Backup_RestoreForm();
                f.FormBorderStyle = FormBorderStyle.FixedSingle;
                f.ShowDialog();
            }
            else
                MessageBox.Show("شما اجازه ی دسترسی ندارید");

        }

        private void storeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            StoreForm f = new StoreForm();
            f.ismanager = this.ismanger;
            f.personStore = this.personStore;
            f.presonBranch = this.personBranch;
            f.FormBorderStyle = FormBorderStyle.FixedSingle;
            f.ShowDialog();
        }

        private void reportToolStripMenuItem_Click(object sender, EventArgs e)
        {
            BranchForm f = new BranchForm();
            f.ismanager = this.ismanger;
            f.personStore = this.personStore;
            f.presonBranch = this.personBranch;
            f.FormBorderStyle = FormBorderStyle.FixedSingle;
            f.ShowDialog();
        }

        private void itemToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ItemForm f = new ItemForm();
            f.FormBorderStyle = FormBorderStyle.FixedSingle;
            f.ShowDialog();
        }

        private void branchInventoryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            BranchInventoryForm f = new BranchInventoryForm();
            f.ismanager = this.ismanger;
            f.personStore = this.personStore;
            f.personBranch = this.personBranch;
            f.FormBorderStyle = FormBorderStyle.FixedSingle;
            f.ShowDialog();
        }

        private void chechOutsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CheckoutsForm f = new CheckoutsForm();
            f.ismanager = this.ismanger;
            f.personStore = this.personStore;
            f.personBranch = this.personBranch;
            f.personID = this.personID;
            f.FormBorderStyle = FormBorderStyle.FixedSingle;
            f.ShowDialog();

        }

        private void querysToolStripMenuItem_Click(object sender, EventArgs e)
        {
            QueryForm f = new QueryForm();
            f.FormBorderStyle = FormBorderStyle.FixedSingle;
            f.ShowDialog();
        }
    }
}
