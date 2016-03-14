namespace Database_Project__store_
{
    partial class StoreForm
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
            this.storeSearch_textBox = new System.Windows.Forms.TextBox();
            this.storeSearch_Btn = new System.Windows.Forms.Button();
            this.storeEdit_Btn = new System.Windows.Forms.Button();
            this.storeDelete_Btn = new System.Windows.Forms.Button();
            this.storeInsert_Btn = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.storeBDate_textBox = new System.Windows.Forms.TextBox();
            this.storeName_textBox = new System.Windows.Forms.TextBox();
            this.storeID_textBox = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 12);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(435, 260);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellClick);
            // 
            // storeSearch_textBox
            // 
            this.storeSearch_textBox.Location = new System.Drawing.Point(596, 241);
            this.storeSearch_textBox.Name = "storeSearch_textBox";
            this.storeSearch_textBox.Size = new System.Drawing.Size(139, 22);
            this.storeSearch_textBox.TabIndex = 16;
            this.storeSearch_textBox.TextChanged += new System.EventHandler(this.storeSearch_textBox_TextChanged);
            // 
            // storeSearch_Btn
            // 
            this.storeSearch_Btn.Location = new System.Drawing.Point(453, 233);
            this.storeSearch_Btn.Name = "storeSearch_Btn";
            this.storeSearch_Btn.Size = new System.Drawing.Size(137, 39);
            this.storeSearch_Btn.TabIndex = 15;
            this.storeSearch_Btn.Text = "Search";
            this.storeSearch_Btn.UseVisualStyleBackColor = true;
            this.storeSearch_Btn.Click += new System.EventHandler(this.storeSearch_Btn_Click);
            // 
            // storeEdit_Btn
            // 
            this.storeEdit_Btn.Location = new System.Drawing.Point(453, 188);
            this.storeEdit_Btn.Name = "storeEdit_Btn";
            this.storeEdit_Btn.Size = new System.Drawing.Size(282, 39);
            this.storeEdit_Btn.TabIndex = 14;
            this.storeEdit_Btn.Text = "Edit";
            this.storeEdit_Btn.UseVisualStyleBackColor = true;
            this.storeEdit_Btn.Click += new System.EventHandler(this.storeEdit_Btn_Click);
            // 
            // storeDelete_Btn
            // 
            this.storeDelete_Btn.Location = new System.Drawing.Point(453, 143);
            this.storeDelete_Btn.Name = "storeDelete_Btn";
            this.storeDelete_Btn.Size = new System.Drawing.Size(282, 39);
            this.storeDelete_Btn.TabIndex = 13;
            this.storeDelete_Btn.Text = "Delete";
            this.storeDelete_Btn.UseVisualStyleBackColor = true;
            this.storeDelete_Btn.Click += new System.EventHandler(this.storeDelete_Btn_Click);
            // 
            // storeInsert_Btn
            // 
            this.storeInsert_Btn.Location = new System.Drawing.Point(453, 98);
            this.storeInsert_Btn.Name = "storeInsert_Btn";
            this.storeInsert_Btn.Size = new System.Drawing.Size(282, 39);
            this.storeInsert_Btn.TabIndex = 12;
            this.storeInsert_Btn.Text = "Insert";
            this.storeInsert_Btn.UseVisualStyleBackColor = true;
            this.storeInsert_Btn.Click += new System.EventHandler(this.storeInsert_Btn_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(764, 15);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(63, 17);
            this.label3.TabIndex = 22;
            this.label3.Text = ": StoreID";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(764, 44);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 17);
            this.label2.TabIndex = 21;
            this.label2.Text = ": Name";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(764, 73);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(55, 17);
            this.label1.TabIndex = 20;
            this.label1.Text = ": BDate";
            // 
            // storeBDate_textBox
            // 
            this.storeBDate_textBox.Location = new System.Drawing.Point(453, 70);
            this.storeBDate_textBox.Name = "storeBDate_textBox";
            this.storeBDate_textBox.Size = new System.Drawing.Size(282, 22);
            this.storeBDate_textBox.TabIndex = 19;
            // 
            // storeName_textBox
            // 
            this.storeName_textBox.Location = new System.Drawing.Point(453, 41);
            this.storeName_textBox.Name = "storeName_textBox";
            this.storeName_textBox.Size = new System.Drawing.Size(282, 22);
            this.storeName_textBox.TabIndex = 18;
            // 
            // storeID_textBox
            // 
            this.storeID_textBox.Location = new System.Drawing.Point(453, 12);
            this.storeID_textBox.Name = "storeID_textBox";
            this.storeID_textBox.Size = new System.Drawing.Size(282, 22);
            this.storeID_textBox.TabIndex = 17;
            // 
            // StoreForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(844, 285);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.storeBDate_textBox);
            this.Controls.Add(this.storeName_textBox);
            this.Controls.Add(this.storeID_textBox);
            this.Controls.Add(this.storeSearch_textBox);
            this.Controls.Add(this.storeSearch_Btn);
            this.Controls.Add(this.storeEdit_Btn);
            this.Controls.Add(this.storeDelete_Btn);
            this.Controls.Add(this.storeInsert_Btn);
            this.Controls.Add(this.dataGridView1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "StoreForm";
            this.Text = "StoreForm";
            this.Load += new System.EventHandler(this.StoreForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.TextBox storeSearch_textBox;
        private System.Windows.Forms.Button storeSearch_Btn;
        private System.Windows.Forms.Button storeEdit_Btn;
        private System.Windows.Forms.Button storeDelete_Btn;
        private System.Windows.Forms.Button storeInsert_Btn;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox storeBDate_textBox;
        private System.Windows.Forms.TextBox storeName_textBox;
        private System.Windows.Forms.TextBox storeID_textBox;
    }
}