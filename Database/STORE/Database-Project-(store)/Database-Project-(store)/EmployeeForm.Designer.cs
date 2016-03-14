namespace Database_Project__store_
{
    partial class EmployeeForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.empEdit_Btn = new System.Windows.Forms.Button();
            this.empDelete_Btn = new System.Windows.Forms.Button();
            this.empSearch_Btn = new System.Windows.Forms.Button();
            this.empInsert_Btn = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.empID_Textbox = new System.Windows.Forms.TextBox();
            this.empWorksFor_Textbox = new System.Windows.Forms.TextBox();
            this.empLname_Textbox = new System.Windows.Forms.TextBox();
            this.empSalary_Textbox = new System.Windows.Forms.TextBox();
            this.empFname_Textbox = new System.Windows.Forms.TextBox();
            this.empType_textbox = new System.Windows.Forms.TextBox();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.empSearchTextBox = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.showAllEmp_textbox = new System.Windows.Forms.Button();
            this.insertAsView1_Btn = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.showBranchManager = new System.Windows.Forms.Button();
            this.insertWithProcedure = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // empEdit_Btn
            // 
            this.empEdit_Btn.Location = new System.Drawing.Point(790, 343);
            this.empEdit_Btn.Name = "empEdit_Btn";
            this.empEdit_Btn.Size = new System.Drawing.Size(250, 38);
            this.empEdit_Btn.TabIndex = 1;
            this.empEdit_Btn.Text = "Edit";
            this.empEdit_Btn.UseVisualStyleBackColor = true;
            this.empEdit_Btn.Click += new System.EventHandler(this.empEdit_Btn_Click);
            // 
            // empDelete_Btn
            // 
            this.empDelete_Btn.Location = new System.Drawing.Point(790, 299);
            this.empDelete_Btn.Name = "empDelete_Btn";
            this.empDelete_Btn.Size = new System.Drawing.Size(250, 38);
            this.empDelete_Btn.TabIndex = 2;
            this.empDelete_Btn.Text = "Delete";
            this.empDelete_Btn.UseVisualStyleBackColor = true;
            this.empDelete_Btn.Click += new System.EventHandler(this.empDelete_Btn_Click);
            // 
            // empSearch_Btn
            // 
            this.empSearch_Btn.Location = new System.Drawing.Point(790, 387);
            this.empSearch_Btn.Name = "empSearch_Btn";
            this.empSearch_Btn.Size = new System.Drawing.Size(128, 38);
            this.empSearch_Btn.TabIndex = 3;
            this.empSearch_Btn.Text = "Search";
            this.empSearch_Btn.UseVisualStyleBackColor = true;
            this.empSearch_Btn.Click += new System.EventHandler(this.empSearch_Btn_Click);
            // 
            // empInsert_Btn
            // 
            this.empInsert_Btn.Location = new System.Drawing.Point(790, 255);
            this.empInsert_Btn.Name = "empInsert_Btn";
            this.empInsert_Btn.Size = new System.Drawing.Size(250, 38);
            this.empInsert_Btn.TabIndex = 4;
            this.empInsert_Btn.Text = "Insert";
            this.empInsert_Btn.UseVisualStyleBackColor = true;
            this.empInsert_Btn.Click += new System.EventHandler(this.empInsert_Btn_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(1052, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(21, 17);
            this.label1.TabIndex = 5;
            this.label1.Text = "ID";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(1052, 101);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(51, 17);
            this.label2.TabIndex = 6;
            this.label2.Text = "Fname";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(1052, 144);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(51, 17);
            this.label3.TabIndex = 7;
            this.label3.Text = "Lname";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(1052, 58);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(48, 17);
            this.label5.TabIndex = 9;
            this.label5.Text = "Salary";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(1052, 187);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(69, 17);
            this.label8.TabIndex = 12;
            this.label8.Text = "Works for";
            // 
            // empID_Textbox
            // 
            this.empID_Textbox.Location = new System.Drawing.Point(790, 12);
            this.empID_Textbox.Name = "empID_Textbox";
            this.empID_Textbox.Size = new System.Drawing.Size(250, 22);
            this.empID_Textbox.TabIndex = 14;
            // 
            // empWorksFor_Textbox
            // 
            this.empWorksFor_Textbox.Location = new System.Drawing.Point(790, 184);
            this.empWorksFor_Textbox.Name = "empWorksFor_Textbox";
            this.empWorksFor_Textbox.Size = new System.Drawing.Size(250, 22);
            this.empWorksFor_Textbox.TabIndex = 15;
            // 
            // empLname_Textbox
            // 
            this.empLname_Textbox.Location = new System.Drawing.Point(790, 141);
            this.empLname_Textbox.Name = "empLname_Textbox";
            this.empLname_Textbox.Size = new System.Drawing.Size(250, 22);
            this.empLname_Textbox.TabIndex = 16;
            // 
            // empSalary_Textbox
            // 
            this.empSalary_Textbox.Location = new System.Drawing.Point(790, 55);
            this.empSalary_Textbox.Name = "empSalary_Textbox";
            this.empSalary_Textbox.Size = new System.Drawing.Size(250, 22);
            this.empSalary_Textbox.TabIndex = 18;
            // 
            // empFname_Textbox
            // 
            this.empFname_Textbox.Location = new System.Drawing.Point(790, 98);
            this.empFname_Textbox.Name = "empFname_Textbox";
            this.empFname_Textbox.Size = new System.Drawing.Size(250, 22);
            this.empFname_Textbox.TabIndex = 19;
            // 
            // empType_textbox
            // 
            this.empType_textbox.Location = new System.Drawing.Point(790, 227);
            this.empType_textbox.Name = "empType_textbox";
            this.empType_textbox.Size = new System.Drawing.Size(250, 22);
            this.empType_textbox.TabIndex = 20;
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 12);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(772, 317);
            this.dataGridView1.TabIndex = 22;
            this.dataGridView1.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellClick);
            // 
            // empSearchTextBox
            // 
            this.empSearchTextBox.Location = new System.Drawing.Point(924, 395);
            this.empSearchTextBox.Name = "empSearchTextBox";
            this.empSearchTextBox.Size = new System.Drawing.Size(116, 22);
            this.empSearchTextBox.TabIndex = 23;
            this.empSearchTextBox.TextChanged += new System.EventHandler(this.empSearchTextBox_TextChanged);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(1052, 230);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(40, 17);
            this.label7.TabIndex = 11;
            this.label7.Text = "Type";
            // 
            // showAllEmp_textbox
            // 
            this.showAllEmp_textbox.Location = new System.Drawing.Point(542, 334);
            this.showAllEmp_textbox.Name = "showAllEmp_textbox";
            this.showAllEmp_textbox.Size = new System.Drawing.Size(242, 91);
            this.showAllEmp_textbox.TabIndex = 24;
            this.showAllEmp_textbox.Text = "Show All Employee";
            this.showAllEmp_textbox.UseVisualStyleBackColor = true;
            this.showAllEmp_textbox.Click += new System.EventHandler(this.showAllEmp_textbox_Click);
            // 
            // insertAsView1_Btn
            // 
            this.insertAsView1_Btn.Location = new System.Drawing.Point(12, 334);
            this.insertAsView1_Btn.Name = "insertAsView1_Btn";
            this.insertAsView1_Btn.Size = new System.Drawing.Size(259, 29);
            this.insertAsView1_Btn.TabIndex = 25;
            this.insertAsView1_Btn.Text = "Insert As View1";
            this.insertAsView1_Btn.UseVisualStyleBackColor = true;
            this.insertAsView1_Btn.Click += new System.EventHandler(this.insertAsView1_Btn_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 371);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(0, 17);
            this.label4.TabIndex = 26;
            // 
            // showBranchManager
            // 
            this.showBranchManager.Location = new System.Drawing.Point(11, 395);
            this.showBranchManager.Name = "showBranchManager";
            this.showBranchManager.Size = new System.Drawing.Size(260, 30);
            this.showBranchManager.TabIndex = 27;
            this.showBranchManager.Text = "Show branch Manager";
            this.showBranchManager.UseVisualStyleBackColor = true;
            this.showBranchManager.Click += new System.EventHandler(this.showBranchManager_Click);
            // 
            // insertWithProcedure
            // 
            this.insertWithProcedure.Location = new System.Drawing.Point(277, 334);
            this.insertWithProcedure.Name = "insertWithProcedure";
            this.insertWithProcedure.Size = new System.Drawing.Size(259, 91);
            this.insertWithProcedure.TabIndex = 28;
            this.insertWithProcedure.Text = "Insert Into Employee Table with procedure";
            this.insertWithProcedure.UseVisualStyleBackColor = true;
            this.insertWithProcedure.Click += new System.EventHandler(this.insertWithProcedure_Click);
            // 
            // EmployeeForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(1133, 442);
            this.Controls.Add(this.insertWithProcedure);
            this.Controls.Add(this.showBranchManager);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.insertAsView1_Btn);
            this.Controls.Add(this.showAllEmp_textbox);
            this.Controls.Add(this.empSearchTextBox);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.empType_textbox);
            this.Controls.Add(this.empFname_Textbox);
            this.Controls.Add(this.empSalary_Textbox);
            this.Controls.Add(this.empLname_Textbox);
            this.Controls.Add(this.empWorksFor_Textbox);
            this.Controls.Add(this.empID_Textbox);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.empInsert_Btn);
            this.Controls.Add(this.empSearch_Btn);
            this.Controls.Add(this.empDelete_Btn);
            this.Controls.Add(this.empEdit_Btn);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "EmployeeForm";
            this.Text = "EmployeForm";
            this.Load += new System.EventHandler(this.EmployeeForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button empEdit_Btn;
        private System.Windows.Forms.Button empDelete_Btn;
        private System.Windows.Forms.Button empSearch_Btn;
        private System.Windows.Forms.Button empInsert_Btn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox empID_Textbox;
        private System.Windows.Forms.TextBox empWorksFor_Textbox;
        private System.Windows.Forms.TextBox empLname_Textbox;
        private System.Windows.Forms.TextBox empSalary_Textbox;
        private System.Windows.Forms.TextBox empFname_Textbox;
        private System.Windows.Forms.TextBox empType_textbox;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.TextBox empSearchTextBox;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button showAllEmp_textbox;
        private System.Windows.Forms.Button insertAsView1_Btn;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button showBranchManager;
        private System.Windows.Forms.Button insertWithProcedure;
    }
}