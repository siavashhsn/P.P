namespace Database_Project__store_
{
    partial class CustomerForm
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
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.cusInsert_Btn = new System.Windows.Forms.Button();
            this.cusDelete_Btn = new System.Windows.Forms.Button();
            this.cusEdit_Btn = new System.Windows.Forms.Button();
            this.cusSearch_Btn = new System.Windows.Forms.Button();
            this.cusID_textBox = new System.Windows.Forms.TextBox();
            this.cusBranchID_textBox = new System.Windows.Forms.TextBox();
            this.cusJoinedDate_textBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.cusSearch_textBox = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 22);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(434, 270);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellClick);
            // 
            // cusInsert_Btn
            // 
            this.cusInsert_Btn.Location = new System.Drawing.Point(462, 118);
            this.cusInsert_Btn.Name = "cusInsert_Btn";
            this.cusInsert_Btn.Size = new System.Drawing.Size(282, 39);
            this.cusInsert_Btn.TabIndex = 1;
            this.cusInsert_Btn.Text = "Insert";
            this.cusInsert_Btn.UseVisualStyleBackColor = true;
            this.cusInsert_Btn.Click += new System.EventHandler(this.cusInsert_Btn_Click);
            // 
            // cusDelete_Btn
            // 
            this.cusDelete_Btn.Location = new System.Drawing.Point(462, 163);
            this.cusDelete_Btn.Name = "cusDelete_Btn";
            this.cusDelete_Btn.Size = new System.Drawing.Size(282, 39);
            this.cusDelete_Btn.TabIndex = 2;
            this.cusDelete_Btn.Text = "Delete";
            this.cusDelete_Btn.UseVisualStyleBackColor = true;
            this.cusDelete_Btn.Click += new System.EventHandler(this.cusDelete_Btn_Click);
            // 
            // cusEdit_Btn
            // 
            this.cusEdit_Btn.Location = new System.Drawing.Point(462, 208);
            this.cusEdit_Btn.Name = "cusEdit_Btn";
            this.cusEdit_Btn.Size = new System.Drawing.Size(282, 39);
            this.cusEdit_Btn.TabIndex = 3;
            this.cusEdit_Btn.Text = "Edit";
            this.cusEdit_Btn.UseVisualStyleBackColor = true;
            this.cusEdit_Btn.Click += new System.EventHandler(this.cusEdit_Btn_Click);
            // 
            // cusSearch_Btn
            // 
            this.cusSearch_Btn.Location = new System.Drawing.Point(462, 253);
            this.cusSearch_Btn.Name = "cusSearch_Btn";
            this.cusSearch_Btn.Size = new System.Drawing.Size(137, 39);
            this.cusSearch_Btn.TabIndex = 4;
            this.cusSearch_Btn.Text = "Search";
            this.cusSearch_Btn.UseVisualStyleBackColor = true;
            this.cusSearch_Btn.Click += new System.EventHandler(this.cusSearch_Btn_Click);
            // 
            // cusID_textBox
            // 
            this.cusID_textBox.Location = new System.Drawing.Point(462, 22);
            this.cusID_textBox.Name = "cusID_textBox";
            this.cusID_textBox.Size = new System.Drawing.Size(282, 22);
            this.cusID_textBox.TabIndex = 5;
            // 
            // cusBranchID_textBox
            // 
            this.cusBranchID_textBox.Location = new System.Drawing.Point(462, 51);
            this.cusBranchID_textBox.Name = "cusBranchID_textBox";
            this.cusBranchID_textBox.Size = new System.Drawing.Size(282, 22);
            this.cusBranchID_textBox.TabIndex = 6;
            this.cusBranchID_textBox.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // cusJoinedDate_textBox
            // 
            this.cusJoinedDate_textBox.Location = new System.Drawing.Point(462, 80);
            this.cusJoinedDate_textBox.Name = "cusJoinedDate_textBox";
            this.cusJoinedDate_textBox.Size = new System.Drawing.Size(282, 22);
            this.cusJoinedDate_textBox.TabIndex = 7;
            this.cusJoinedDate_textBox.TextChanged += new System.EventHandler(this.textBox3_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(773, 83);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(86, 17);
            this.label1.TabIndex = 8;
            this.label1.Text = ": joined date";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(773, 54);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(74, 17);
            this.label2.TabIndex = 9;
            this.label2.Text = ": BranchID";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(773, 25);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(89, 17);
            this.label3.TabIndex = 10;
            this.label3.Text = ": CustomerID";
            // 
            // cusSearch_textBox
            // 
            this.cusSearch_textBox.Location = new System.Drawing.Point(605, 261);
            this.cusSearch_textBox.Name = "cusSearch_textBox";
            this.cusSearch_textBox.Size = new System.Drawing.Size(139, 22);
            this.cusSearch_textBox.TabIndex = 11;
            this.cusSearch_textBox.TextChanged += new System.EventHandler(this.cusSearch_textBox_TextChanged);
            // 
            // CustomerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(872, 321);
            this.Controls.Add(this.cusSearch_textBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cusJoinedDate_textBox);
            this.Controls.Add(this.cusBranchID_textBox);
            this.Controls.Add(this.cusID_textBox);
            this.Controls.Add(this.cusSearch_Btn);
            this.Controls.Add(this.cusEdit_Btn);
            this.Controls.Add(this.cusDelete_Btn);
            this.Controls.Add(this.cusInsert_Btn);
            this.Controls.Add(this.dataGridView1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "CustomerForm";
            this.Text = "CustomerForm";
            this.Load += new System.EventHandler(this.CustomerForm_Load_1);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button cusInsert_Btn;
        private System.Windows.Forms.Button cusDelete_Btn;
        private System.Windows.Forms.Button cusEdit_Btn;
        private System.Windows.Forms.Button cusSearch_Btn;
        private System.Windows.Forms.TextBox cusID_textBox;
        private System.Windows.Forms.TextBox cusBranchID_textBox;
        private System.Windows.Forms.TextBox cusJoinedDate_textBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox cusSearch_textBox;
    }
}