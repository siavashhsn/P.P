using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace WindowsFormsApplication48
{
    public partial class MainForm : Form
    {
        public MainForm()
        {   
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            pictureBox1.Width = Width;
            pictureBox1.Height = Height - 40;
        }

        private void کاربرToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void دانشجوToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            NewStudent ns1 = new NewStudent();
            ns1.ShowDialog();
        }

        private void دانشجوToolStripMenuItem2_Click(object sender, EventArgs e)
        {
            SearchStudent ss = new SearchStudent();
            ss.ShowDialog();
        }

        private void دانشجوToolStripMenuItem3_Click(object sender, EventArgs e)
        {


            RPTStudent rp1 = new RPTStudent();
            rp1.ShowDialog();
        }
    }
}
