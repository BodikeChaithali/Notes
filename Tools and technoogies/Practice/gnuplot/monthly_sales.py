import matplotlib.pyplot as plt

products = ['Laptops', 'Smartphones', 'Headphones', 'Monitors', 'Keyboards']
units_sold = [150, 300, 250, 130, 180]
colors=['blue','yellow','green','orange','red']
plt.figure(figsize=(10,6))
bars=plt.bar(products, units_sold, color=colors)
plt.xlabel("Product Category",fontname="Times New Roman")
plt.ylabel("Units Sold",fontname='Times New Roman')
plt.title("Monthly Sales Distribution of Products")
plt.grid(axis='y',linestyle='--',alpha=0.7)
plt.tight_layout()
plt.savefig("sales_barplot.pdf")
plt.bar_label(bars, labels=[f"{v}" for v in units_sold])
plt.show()
