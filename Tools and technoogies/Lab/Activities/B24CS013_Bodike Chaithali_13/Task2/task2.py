import matplotlib.pyplot as plt

products = ['Laptops', 'Smartphones', 'Headphones', 'Monitors', 'Keyboards']
units_sold = [150, 300, 250, 130, 180]
colors = ['#ff9999', '#66b3ff', '#99ff99', '#ffcc99', '#c2c2f0']

plt.figure(figsize=(10, 6))

bars = plt.bar(products, units_sold, color=colors)

for bar in bars:
    plt.text(bar.get_x() + bar.get_width()/2,bar.get_height() + 5,str(bar.get_height()),ha='center',fontsize=10,fontname='Times New Roman')

plt.xlabel("Product Category", fontsize=12, fontname='Times New Roman')
plt.ylabel("Units Sold", fontsize=12, fontname='Times New Roman')
plt.title("Monthly Sales Distribution of Products", fontsize=14, fontname='Times New Roman', fontweight='bold')

plt.grid(axis='y', linestyle='--', alpha=0.7)

plt.tight_layout()
plt.savefig("sales_barplot.pdf")
plt.show()
