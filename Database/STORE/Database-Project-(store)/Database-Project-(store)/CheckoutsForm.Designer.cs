namespace Database_Project__store_
{
    partial class CheckoutsForm
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
            this.branchID_textBox = new System.Windows.Forms.TextBox();
            this.checkoutPrice_textBox = new System.Windows.Forms.TextBox();
            this.employeeID_textBox = new System.Windows.Forms.TextBox();
            this.chechoutID_textBox = new System.Windows.Forms.TextBox();
            this.customerID_textBox = new System.Windows.Forms.TextBox();
            this.checkSearch_textBox = new System.Windows.Forms.TextBox();
            this.checkSearch_Btn = new System.Windows.Forms.Button();
            this.checkEdit_Btn = new System.Windows.Forms.Button();
            this.checkDelete_Btn = new System.Windows.Forms.Button();
            this.checkInsert_Btn = new System.Windows.Forms.Button();
            this.dataGridView = new System.Windows.Forms.DataGridView();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.ItemdataGridView = new System.Windows.Forms.DataGridView();
            this.checkoutItemdataGridView = new System.Windows.Forms.DataGridView();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label6 = new System.Windows.Forms.Label();
            this.qtyOfItem_textBox = new System.Windows.Forms.TextBox();
            this.selectTheItem_Btn = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.deleteTheItem_Btn = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.editQtyOfItem_textBox = new System.Windows.Forms.TextBox();
            this.editTheQtyOfItem_Btn = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.report_Btn = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ItemdataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.checkoutItemdataGridView)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // branchID_textBox
            // 
            this.branchID_textBox.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.branchID_textBox.Location = new System.Drawing.Point(795, 398);
            this.branchID_textBox.Name = "branchID_textBox";
            this.branchID_textBox.ReadOnly = true;
            this.branchID_textBox.Size = new System.Drawing.Size(282, 22);
            this.branchID_textBox.TabIndex = 38;
            // 
            // checkoutPrice_textBox
            // 
            this.checkoutPrice_textBox.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.checkoutPrice_textBox.Location = new System.Drawing.Point(795, 426);
            this.checkoutPrice_textBox.Name = "checkoutPrice_textBox";
            this.checkoutPrice_textBox.Size = new System.Drawing.Size(282, 22);
            this.checkoutPrice_textBox.TabIndex = 37;
            // 
            // employeeID_textBox
            // 
            this.employeeID_textBox.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.employeeID_textBox.Location = new System.Drawing.Point(795, 370);
            this.employeeID_textBox.Name = "employeeID_textBox";
            this.employeeID_textBox.ReadOnly = true;
            this.employeeID_textBox.Size = new System.Drawing.Size(282, 22);
            this.employeeID_textBox.TabIndex = 36;
            // 
            // chechoutID_textBox
            // 
            this.chechoutID_textBox.Location = new System.Drawing.Point(795, 314);
            this.chechoutID_textBox.Name = "chechoutID_textBox";
            this.chechoutID_textBox.Size = new System.Drawing.Size(282, 22);
            this.chechoutID_textBox.TabIndex = 35;
            // 
            // customerID_textBox
            // 
            this.customerID_textBox.Location = new System.Drawing.Point(795, 342);
            this.customerID_textBox.Name = "customerID_textBox";
            this.customerID_textBox.Size = new System.Drawing.Size(282, 22);
            this.customerID_textBox.TabIndex = 34;
            // 
            // checkSearch_textBox
            // 
            this.checkSearch_textBox.Location = new System.Drawing.Point(938, 597);
            this.checkSearch_textBox.Name = "checkSearch_textBox";
            this.checkSearch_textBox.Size = new System.Drawing.Size(139, 22);
            this.checkSearch_textBox.TabIndex = 33;
            this.checkSearch_textBox.TextChanged += new System.EventHandler(this.checkSearch_textBox_TextChanged);
            // 
            // checkSearch_Btn
            // 
            this.checkSearch_Btn.Location = new System.Drawing.Point(795, 589);
            this.checkSearch_Btn.Name = "checkSearch_Btn";
            this.checkSearch_Btn.Size = new System.Drawing.Size(137, 39);
            this.checkSearch_Btn.TabIndex = 32;
            this.checkSearch_Btn.Text = "Search";
            this.checkSearch_Btn.UseVisualStyleBackColor = true;
            this.checkSearch_Btn.Click += new System.EventHandler(this.checkSearch_Btn_Click);
            // 
            // checkEdit_Btn
            // 
            this.checkEdit_Btn.Location = new System.Drawing.Point(795, 544);
            this.checkEdit_Btn.Name = "checkEdit_Btn";
            this.checkEdit_Btn.Size = new System.Drawing.Size(282, 39);
            this.checkEdit_Btn.TabIndex = 31;
            this.checkEdit_Btn.Text = "Edit";
            this.checkEdit_Btn.UseVisualStyleBackColor = true;
            this.checkEdit_Btn.Click += new System.EventHandler(this.checkEdit_Btn_Click);
            // 
            // checkDelete_Btn
            // 
            this.checkDelete_Btn.Location = new System.Drawing.Point(795, 499);
            this.checkDelete_Btn.Name = "checkDelete_Btn";
            this.checkDelete_Btn.Size = new System.Drawing.Size(282, 39);
            this.checkDelete_Btn.TabIndex = 30;
            this.checkDelete_Btn.Text = "Delete";
            this.checkDelete_Btn.UseVisualStyleBackColor = true;
            this.checkDelete_Btn.Click += new System.EventHandler(this.checkDelete_Btn_Click);
            // 
            // checkInsert_Btn
            // 
            this.checkInsert_Btn.Location = new System.Drawing.Point(795, 454);
            this.checkInsert_Btn.Name = "checkInsert_Btn";
            this.checkInsert_Btn.Size = new System.Drawing.Size(282, 39);
            this.checkInsert_Btn.TabIndex = 29;
            this.checkInsert_Btn.Text = "Insert";
            this.checkInsert_Btn.UseVisualStyleBackColor = true;
            this.checkInsert_Btn.Click += new System.EventHandler(this.checkInsert_Btn_Click);
            // 
            // dataGridView
            // 
            this.dataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView.Location = new System.Drawing.Point(12, 314);
            this.dataGridView.Name = "dataGridView";
            this.dataGridView.RowTemplate.Height = 24;
            this.dataGridView.Size = new System.Drawing.Size(777, 314);
            this.dataGridView.TabIndex = 28;
            this.dataGridView.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView_CellClick);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(1085, 429);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(107, 17);
            this.label5.TabIndex = 43;
            this.label5.Text = ":Checkout Price";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(1085, 401);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(70, 17);
            this.label4.TabIndex = 42;
            this.label4.Text = ":BranchID";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(1085, 373);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(87, 17);
            this.label3.TabIndex = 41;
            this.label3.Text = ":EmployeeID";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(1085, 345);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(85, 17);
            this.label2.TabIndex = 40;
            this.label2.Text = ":CustomerID";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(1085, 317);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(85, 17);
            this.label1.TabIndex = 39;
            this.label1.Text = ":ChechoutID";
            // 
            // ItemdataGridView
            // 
            this.ItemdataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.ItemdataGridView.Location = new System.Drawing.Point(21, 21);
            this.ItemdataGridView.Name = "ItemdataGridView";
            this.ItemdataGridView.RowTemplate.Height = 24;
            this.ItemdataGridView.Size = new System.Drawing.Size(444, 260);
            this.ItemdataGridView.TabIndex = 44;
            this.ItemdataGridView.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.ItemdataGridView_CellClick);
            // 
            // checkoutItemdataGridView
            // 
            this.checkoutItemdataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.checkoutItemdataGridView.Location = new System.Drawing.Point(6, 21);
            this.checkoutItemdataGridView.Name = "checkoutItemdataGridView";
            this.checkoutItemdataGridView.RowTemplate.Height = 24;
            this.checkoutItemdataGridView.Size = new System.Drawing.Size(432, 260);
            this.checkoutItemdataGridView.TabIndex = 45;
            this.checkoutItemdataGridView.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.checkoutItemdataGridView_CellClick);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.qtyOfItem_textBox);
            this.groupBox1.Controls.Add(this.selectTheItem_Btn);
            this.groupBox1.Location = new System.Drawing.Point(462, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(258, 148);
            this.groupBox1.TabIndex = 46;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Choose The Items";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(17, 69);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(79, 17);
            this.label6.TabIndex = 2;
            this.label6.Text = "Qty Of Item";
            // 
            // qtyOfItem_textBox
            // 
            this.qtyOfItem_textBox.Location = new System.Drawing.Point(102, 66);
            this.qtyOfItem_textBox.Name = "qtyOfItem_textBox";
            this.qtyOfItem_textBox.Size = new System.Drawing.Size(138, 22);
            this.qtyOfItem_textBox.TabIndex = 1;
            // 
            // selectTheItem_Btn
            // 
            this.selectTheItem_Btn.Location = new System.Drawing.Point(20, 30);
            this.selectTheItem_Btn.Name = "selectTheItem_Btn";
            this.selectTheItem_Btn.Size = new System.Drawing.Size(220, 30);
            this.selectTheItem_Btn.TabIndex = 0;
            this.selectTheItem_Btn.Text = "Select The Item";
            this.selectTheItem_Btn.UseVisualStyleBackColor = true;
            this.selectTheItem_Btn.Click += new System.EventHandler(this.selectTheItem_Btn_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.ItemdataGridView);
            this.groupBox2.Location = new System.Drawing.Point(723, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(481, 296);
            this.groupBox2.TabIndex = 47;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Branch Items";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.checkoutItemdataGridView);
            this.groupBox3.Location = new System.Drawing.Point(12, 12);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(444, 296);
            this.groupBox3.TabIndex = 48;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Checkout Items";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.deleteTheItem_Btn);
            this.groupBox4.Controls.Add(this.label7);
            this.groupBox4.Controls.Add(this.editQtyOfItem_textBox);
            this.groupBox4.Controls.Add(this.editTheQtyOfItem_Btn);
            this.groupBox4.Location = new System.Drawing.Point(462, 166);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(258, 142);
            this.groupBox4.TabIndex = 49;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Edit the selected Items";
            // 
            // deleteTheItem_Btn
            // 
            this.deleteTheItem_Btn.Location = new System.Drawing.Point(20, 94);
            this.deleteTheItem_Btn.Name = "deleteTheItem_Btn";
            this.deleteTheItem_Btn.Size = new System.Drawing.Size(220, 30);
            this.deleteTheItem_Btn.TabIndex = 3;
            this.deleteTheItem_Btn.Text = "Delete The Item";
            this.deleteTheItem_Btn.UseVisualStyleBackColor = true;
            this.deleteTheItem_Btn.Click += new System.EventHandler(this.deleteTheItem_Btn_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(17, 69);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(79, 17);
            this.label7.TabIndex = 2;
            this.label7.Text = "Qty Of Item";
            // 
            // editQtyOfItem_textBox
            // 
            this.editQtyOfItem_textBox.Location = new System.Drawing.Point(102, 66);
            this.editQtyOfItem_textBox.Name = "editQtyOfItem_textBox";
            this.editQtyOfItem_textBox.Size = new System.Drawing.Size(138, 22);
            this.editQtyOfItem_textBox.TabIndex = 1;
            // 
            // editTheQtyOfItem_Btn
            // 
            this.editTheQtyOfItem_Btn.Location = new System.Drawing.Point(20, 30);
            this.editTheQtyOfItem_Btn.Name = "editTheQtyOfItem_Btn";
            this.editTheQtyOfItem_Btn.Size = new System.Drawing.Size(220, 30);
            this.editTheQtyOfItem_Btn.TabIndex = 0;
            this.editTheQtyOfItem_Btn.Text = "Edit The QTY Of Item";
            this.editTheQtyOfItem_Btn.UseVisualStyleBackColor = true;
            this.editTheQtyOfItem_Btn.Click += new System.EventHandler(this.editTheQtyOfItem_Btn_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 634);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(382, 45);
            this.button1.TabIndex = 50;
            this.button1.Text = "delete checkouts which has price<10 (procedure)";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(12, 685);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(382, 45);
            this.button2.TabIndex = 51;
            this.button2.Text = "show checkouts which has price>100 (procedure)";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(407, 634);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(382, 45);
            this.button3.TabIndex = 52;
            this.button3.Text = "show checkouts (view)";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // report_Btn
            // 
            this.report_Btn.Location = new System.Drawing.Point(795, 634);
            this.report_Btn.Name = "report_Btn";
            this.report_Btn.Size = new System.Drawing.Size(282, 45);
            this.report_Btn.TabIndex = 53;
            this.report_Btn.Text = "Report";
            this.report_Btn.UseVisualStyleBackColor = true;
            this.report_Btn.Click += new System.EventHandler(this.report_Btn_Click);
            // 
            // CheckoutsForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1223, 736);
            this.Controls.Add(this.report_Btn);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.branchID_textBox);
            this.Controls.Add(this.checkoutPrice_textBox);
            this.Controls.Add(this.employeeID_textBox);
            this.Controls.Add(this.chechoutID_textBox);
            this.Controls.Add(this.customerID_textBox);
            this.Controls.Add(this.checkSearch_textBox);
            this.Controls.Add(this.checkSearch_Btn);
            this.Controls.Add(this.checkEdit_Btn);
            this.Controls.Add(this.checkDelete_Btn);
            this.Controls.Add(this.checkInsert_Btn);
            this.Controls.Add(this.dataGridView);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "CheckoutsForm";
            this.Text = "CheckoutsForm";
            this.Load += new System.EventHandler(this.CheckoutsForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ItemdataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.checkoutItemdataGridView)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox branchID_textBox;
        private System.Windows.Forms.TextBox checkoutPrice_textBox;
        private System.Windows.Forms.TextBox employeeID_textBox;
        private System.Windows.Forms.TextBox chechoutID_textBox;
        private System.Windows.Forms.TextBox customerID_textBox;
        private System.Windows.Forms.TextBox checkSearch_textBox;
        private System.Windows.Forms.Button checkSearch_Btn;
        private System.Windows.Forms.Button checkEdit_Btn;
        private System.Windows.Forms.Button checkDelete_Btn;
        private System.Windows.Forms.Button checkInsert_Btn;
        private System.Windows.Forms.DataGridView dataGridView;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView ItemdataGridView;
        private System.Windows.Forms.DataGridView checkoutItemdataGridView;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox qtyOfItem_textBox;
        private System.Windows.Forms.Button selectTheItem_Btn;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Button deleteTheItem_Btn;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox editQtyOfItem_textBox;
        private System.Windows.Forms.Button editTheQtyOfItem_Btn;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button report_Btn;

    }
}