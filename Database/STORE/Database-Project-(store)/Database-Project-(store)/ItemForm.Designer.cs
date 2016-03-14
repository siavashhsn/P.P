namespace Database_Project__store_
{
    partial class ItemForm
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
            this.itemSearch_textBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.itemPrice_textBox = new System.Windows.Forms.TextBox();
            this.itemName_textBox = new System.Windows.Forms.TextBox();
            this.itemID_textBox = new System.Windows.Forms.TextBox();
            this.itemSearch_Btn = new System.Windows.Forms.Button();
            this.itemEdit_Btn = new System.Windows.Forms.Button();
            this.itemDelete_Btn = new System.Windows.Forms.Button();
            this.itemInsert_Btn = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // itemSearch_textBox
            // 
            this.itemSearch_textBox.Location = new System.Drawing.Point(605, 241);
            this.itemSearch_textBox.Name = "itemSearch_textBox";
            this.itemSearch_textBox.Size = new System.Drawing.Size(139, 22);
            this.itemSearch_textBox.TabIndex = 23;
            this.itemSearch_textBox.TextChanged += new System.EventHandler(this.itemSearch_textBox_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(750, 15);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(55, 17);
            this.label3.TabIndex = 22;
            this.label3.Text = ": ItemID";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(750, 44);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(83, 17);
            this.label2.TabIndex = 21;
            this.label2.Text = ": Item Name";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(750, 73);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(78, 17);
            this.label1.TabIndex = 20;
            this.label1.Text = ": Item Price";
            // 
            // itemPrice_textBox
            // 
            this.itemPrice_textBox.Location = new System.Drawing.Point(462, 70);
            this.itemPrice_textBox.Name = "itemPrice_textBox";
            this.itemPrice_textBox.Size = new System.Drawing.Size(282, 22);
            this.itemPrice_textBox.TabIndex = 19;
            // 
            // itemName_textBox
            // 
            this.itemName_textBox.Location = new System.Drawing.Point(462, 41);
            this.itemName_textBox.Name = "itemName_textBox";
            this.itemName_textBox.Size = new System.Drawing.Size(282, 22);
            this.itemName_textBox.TabIndex = 18;
            // 
            // itemID_textBox
            // 
            this.itemID_textBox.Location = new System.Drawing.Point(462, 12);
            this.itemID_textBox.Name = "itemID_textBox";
            this.itemID_textBox.Size = new System.Drawing.Size(282, 22);
            this.itemID_textBox.TabIndex = 17;
            // 
            // itemSearch_Btn
            // 
            this.itemSearch_Btn.Location = new System.Drawing.Point(462, 233);
            this.itemSearch_Btn.Name = "itemSearch_Btn";
            this.itemSearch_Btn.Size = new System.Drawing.Size(137, 39);
            this.itemSearch_Btn.TabIndex = 16;
            this.itemSearch_Btn.Text = "Search";
            this.itemSearch_Btn.UseVisualStyleBackColor = true;
            this.itemSearch_Btn.Click += new System.EventHandler(this.itemSearch_Btn_Click);
            // 
            // itemEdit_Btn
            // 
            this.itemEdit_Btn.Location = new System.Drawing.Point(462, 188);
            this.itemEdit_Btn.Name = "itemEdit_Btn";
            this.itemEdit_Btn.Size = new System.Drawing.Size(282, 39);
            this.itemEdit_Btn.TabIndex = 15;
            this.itemEdit_Btn.Text = "Edit";
            this.itemEdit_Btn.UseVisualStyleBackColor = true;
            this.itemEdit_Btn.Click += new System.EventHandler(this.itemEdit_Btn_Click);
            // 
            // itemDelete_Btn
            // 
            this.itemDelete_Btn.Location = new System.Drawing.Point(462, 143);
            this.itemDelete_Btn.Name = "itemDelete_Btn";
            this.itemDelete_Btn.Size = new System.Drawing.Size(282, 39);
            this.itemDelete_Btn.TabIndex = 14;
            this.itemDelete_Btn.Text = "Delete";
            this.itemDelete_Btn.UseVisualStyleBackColor = true;
            this.itemDelete_Btn.Click += new System.EventHandler(this.itemDelete_Btn_Click);
            // 
            // itemInsert_Btn
            // 
            this.itemInsert_Btn.Location = new System.Drawing.Point(462, 98);
            this.itemInsert_Btn.Name = "itemInsert_Btn";
            this.itemInsert_Btn.Size = new System.Drawing.Size(282, 39);
            this.itemInsert_Btn.TabIndex = 13;
            this.itemInsert_Btn.Text = "Insert";
            this.itemInsert_Btn.UseVisualStyleBackColor = true;
            this.itemInsert_Btn.Click += new System.EventHandler(this.itemInsert_Btn_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 12);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(444, 260);
            this.dataGridView1.TabIndex = 12;
            this.dataGridView1.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellClick);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 278);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(235, 55);
            this.button1.TabIndex = 24;
            this.button1.Text = "Count of Items (view)";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(12, 339);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(235, 55);
            this.button2.TabIndex = 27;
            this.button2.Text = "Search With Name (procedure)";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(253, 355);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 22);
            this.textBox1.TabIndex = 28;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // ItemForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(840, 425);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.itemSearch_textBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.itemPrice_textBox);
            this.Controls.Add(this.itemName_textBox);
            this.Controls.Add(this.itemID_textBox);
            this.Controls.Add(this.itemSearch_Btn);
            this.Controls.Add(this.itemEdit_Btn);
            this.Controls.Add(this.itemDelete_Btn);
            this.Controls.Add(this.itemInsert_Btn);
            this.Controls.Add(this.dataGridView1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ItemForm";
            this.Text = "ItemForm";
            this.Load += new System.EventHandler(this.ItemForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox itemSearch_textBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox itemPrice_textBox;
        private System.Windows.Forms.TextBox itemName_textBox;
        private System.Windows.Forms.TextBox itemID_textBox;
        private System.Windows.Forms.Button itemSearch_Btn;
        private System.Windows.Forms.Button itemEdit_Btn;
        private System.Windows.Forms.Button itemDelete_Btn;
        private System.Windows.Forms.Button itemInsert_Btn;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox textBox1;
    }
}