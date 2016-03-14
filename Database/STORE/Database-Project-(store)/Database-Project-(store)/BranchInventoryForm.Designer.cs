namespace Database_Project__store_
{
    partial class BranchInventoryForm
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
            this.inventorySearch_textBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.inventoryQty_textBox = new System.Windows.Forms.TextBox();
            this.inventoryItemID_textBox = new System.Windows.Forms.TextBox();
            this.inventoryBranchID_textBox = new System.Windows.Forms.TextBox();
            this.inventorySearch_Btn = new System.Windows.Forms.Button();
            this.inventoryEdit_Btn = new System.Windows.Forms.Button();
            this.inventoryDelete_Btn = new System.Windows.Forms.Button();
            this.inventoryInsert_Btn = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.report_Btn = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            this.SuspendLayout();
            // 
            // inventorySearch_textBox
            // 
            this.inventorySearch_textBox.Location = new System.Drawing.Point(605, 251);
            this.inventorySearch_textBox.Name = "inventorySearch_textBox";
            this.inventorySearch_textBox.Size = new System.Drawing.Size(139, 22);
            this.inventorySearch_textBox.TabIndex = 23;
            this.inventorySearch_textBox.TextChanged += new System.EventHandler(this.inventorySearch_textBox_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(750, 15);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(74, 17);
            this.label3.TabIndex = 22;
            this.label3.Text = ": BranchID";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(750, 44);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(55, 17);
            this.label2.TabIndex = 21;
            this.label2.Text = ": ItemID";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(750, 73);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(69, 17);
            this.label1.TabIndex = 20;
            this.label1.Text = ": Quantity";
            // 
            // inventoryQty_textBox
            // 
            this.inventoryQty_textBox.Location = new System.Drawing.Point(462, 70);
            this.inventoryQty_textBox.Name = "inventoryQty_textBox";
            this.inventoryQty_textBox.Size = new System.Drawing.Size(282, 22);
            this.inventoryQty_textBox.TabIndex = 19;
            // 
            // inventoryItemID_textBox
            // 
            this.inventoryItemID_textBox.Location = new System.Drawing.Point(462, 41);
            this.inventoryItemID_textBox.Name = "inventoryItemID_textBox";
            this.inventoryItemID_textBox.Size = new System.Drawing.Size(282, 22);
            this.inventoryItemID_textBox.TabIndex = 18;
            // 
            // inventoryBranchID_textBox
            // 
            this.inventoryBranchID_textBox.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.inventoryBranchID_textBox.Location = new System.Drawing.Point(462, 12);
            this.inventoryBranchID_textBox.Name = "inventoryBranchID_textBox";
            this.inventoryBranchID_textBox.ReadOnly = true;
            this.inventoryBranchID_textBox.Size = new System.Drawing.Size(282, 22);
            this.inventoryBranchID_textBox.TabIndex = 17;
            // 
            // inventorySearch_Btn
            // 
            this.inventorySearch_Btn.Location = new System.Drawing.Point(462, 243);
            this.inventorySearch_Btn.Name = "inventorySearch_Btn";
            this.inventorySearch_Btn.Size = new System.Drawing.Size(137, 39);
            this.inventorySearch_Btn.TabIndex = 16;
            this.inventorySearch_Btn.Text = "Search by Item";
            this.inventorySearch_Btn.UseVisualStyleBackColor = true;
            this.inventorySearch_Btn.Click += new System.EventHandler(this.inventorySearch_Btn_Click);
            // 
            // inventoryEdit_Btn
            // 
            this.inventoryEdit_Btn.Location = new System.Drawing.Point(462, 198);
            this.inventoryEdit_Btn.Name = "inventoryEdit_Btn";
            this.inventoryEdit_Btn.Size = new System.Drawing.Size(282, 39);
            this.inventoryEdit_Btn.TabIndex = 15;
            this.inventoryEdit_Btn.Text = "Edit";
            this.inventoryEdit_Btn.UseVisualStyleBackColor = true;
            this.inventoryEdit_Btn.Click += new System.EventHandler(this.inventoryEdit_Btn_Click);
            // 
            // inventoryDelete_Btn
            // 
            this.inventoryDelete_Btn.Location = new System.Drawing.Point(462, 153);
            this.inventoryDelete_Btn.Name = "inventoryDelete_Btn";
            this.inventoryDelete_Btn.Size = new System.Drawing.Size(282, 39);
            this.inventoryDelete_Btn.TabIndex = 14;
            this.inventoryDelete_Btn.Text = "Delete";
            this.inventoryDelete_Btn.UseVisualStyleBackColor = true;
            this.inventoryDelete_Btn.Click += new System.EventHandler(this.inventoryDelete_Btn_Click);
            // 
            // inventoryInsert_Btn
            // 
            this.inventoryInsert_Btn.Location = new System.Drawing.Point(462, 108);
            this.inventoryInsert_Btn.Name = "inventoryInsert_Btn";
            this.inventoryInsert_Btn.Size = new System.Drawing.Size(282, 39);
            this.inventoryInsert_Btn.TabIndex = 13;
            this.inventoryInsert_Btn.Text = "Insert";
            this.inventoryInsert_Btn.UseVisualStyleBackColor = true;
            this.inventoryInsert_Btn.Click += new System.EventHandler(this.inventoryInsert_Btn_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 12);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(434, 270);
            this.dataGridView1.TabIndex = 12;
            this.dataGridView1.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellClick);
            // 
            // dataGridView2
            // 
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Location = new System.Drawing.Point(839, 15);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowTemplate.Height = 24;
            this.dataGridView2.Size = new System.Drawing.Size(434, 270);
            this.dataGridView2.TabIndex = 24;
            this.dataGridView2.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView2_CellClick);
            this.dataGridView2.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView2_CellContentClick);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 288);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(434, 55);
            this.button1.TabIndex = 25;
            this.button1.Text = "Employee stores  inventory(view)";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(12, 349);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(434, 55);
            this.button2.TabIndex = 26;
            this.button2.Text = "+10 the employee branchs items(procedure)";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // report_Btn
            // 
            this.report_Btn.Location = new System.Drawing.Point(839, 291);
            this.report_Btn.Name = "report_Btn";
            this.report_Btn.Size = new System.Drawing.Size(196, 113);
            this.report_Btn.TabIndex = 27;
            this.report_Btn.Text = "Report";
            this.report_Btn.UseVisualStyleBackColor = true;
            this.report_Btn.Click += new System.EventHandler(this.report_Btn_Click);
            // 
            // BranchInventoryForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1285, 422);
            this.Controls.Add(this.report_Btn);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dataGridView2);
            this.Controls.Add(this.inventorySearch_textBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.inventoryQty_textBox);
            this.Controls.Add(this.inventoryItemID_textBox);
            this.Controls.Add(this.inventoryBranchID_textBox);
            this.Controls.Add(this.inventorySearch_Btn);
            this.Controls.Add(this.inventoryEdit_Btn);
            this.Controls.Add(this.inventoryDelete_Btn);
            this.Controls.Add(this.inventoryInsert_Btn);
            this.Controls.Add(this.dataGridView1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "BranchInventoryForm";
            this.Text = "BranchInventoryForm";
            this.Load += new System.EventHandler(this.BranchInventoryForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox inventorySearch_textBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox inventoryQty_textBox;
        private System.Windows.Forms.TextBox inventoryItemID_textBox;
        private System.Windows.Forms.TextBox inventoryBranchID_textBox;
        private System.Windows.Forms.Button inventorySearch_Btn;
        private System.Windows.Forms.Button inventoryEdit_Btn;
        private System.Windows.Forms.Button inventoryDelete_Btn;
        private System.Windows.Forms.Button inventoryInsert_Btn;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button report_Btn;
    }
}