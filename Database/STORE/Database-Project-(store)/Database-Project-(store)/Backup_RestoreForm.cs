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

namespace Database_Project__store_
{
    public partial class Backup_RestoreForm : Form
    {
        public Backup_RestoreForm()
        {
            InitializeComponent();
        }

        private void backup_Btn_Click(object sender, EventArgs e)
        {
            myData md = new myData();
            md.strsql = "backup database STORE to disk='D:\\Database_Backup\\STORE-" + DateTime.Now.Ticks.ToString() + ".bak'";
            md.manData();
        }

        private void restore_Btn_Click(object sender, EventArgs e)
        {
            //string location = "";
            //OpenFileDialog dlg = new OpenFileDialog();
            //dlg.Filter = "Backup Files(*.bak)|*.bak|All Files(*.*)|*.*";
            //dlg.FilterIndex = 0;
            //if(dlg.ShowDialog() == DialogResult.OK)
            //{
            //    location = dlg.FileName;
            //}

            //myData md = new myData();
            //md.strsql = "restore database STORE from disk='" + location + "' with norecovery";
            //md.manData();
            OpenFileDialog sfd = new OpenFileDialog();
            string str = string.Empty;
            sfd.Filter = @"backup files(*.bak)|*.bak|all files(*.*)|*.*";
            sfd.FilterIndex = 1;
            sfd.Title = "Open BackUp Files";
            if (sfd.ShowDialog() == DialogResult.OK)
            {
                str = sfd.FileName;

                SqlConnection con1 = new SqlConnection();
                con1.ConnectionString = ConfigurationManager.ConnectionStrings["ConStr1"].ConnectionString;
                con1.Open();
                myData md = new myData();
                md.strsql = "alter database STORE set MULTI_USER with ROLLBACK IMMEDIATE " + " USE MASTER " + " restore database STORE from disc='" + str + "' WITH REPLACE";
                md.manData();
            }
        }
    }
}
