import matplotlib.pyplot as plt

categories = ['Rent', 'Groceries', 'Utilities', 'Transportation', 'Entertainment', 'Savings']
expenses = [1200, 450, 200, 150, 300, 700]

colors = ['#ff9999','#66b3ff','#99ff99','#ffcc99','#c2c2f0','#ffb3e6']
explode = [0.1, 0, 0, 0, 0, 0]

plt.figure(figsize=(8,8))
plt.pie(expenses, labels=categories, autopct='%1.1f%%', startangle=90, colors=colors, explode=explode, shadow=True)
plt.title('Monthly Household Expenditure Breakdown', fontsize=14, loc='center', pad=20)
plt.legend(categories, loc='best', bbox_to_anchor=(1, 0.5))
plt.tight_layout()
plt.savefig('monthly_expenses.pdf', format='pdf')
plt.close()
