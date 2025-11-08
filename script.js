let transactions = [];

const balance = document.getElementById("balance");
const income = document.getElementById("income");
const expense = document.getElementById("expense");
const list = document.getElementById("list");
const addBtn = document.getElementById("add");

addBtn.addEventListener("click", () => {
  const desc = document.getElementById("desc").value;
  const amount = parseFloat(document.getElementById("amount").value);

  if (!desc || isNaN(amount)) {
    alert("Please enter a valid description and amount!");
    return;
  }

  const transaction = { desc, amount };
  transactions.push(transaction);
  updateUI();
  document.getElementById("desc").value = "";
  document.getElementById("amount").value = "";
});

function updateUI() {
  list.innerHTML = "";
  let totalIncome = 0;
  let totalExpense = 0;

  transactions.forEach((t) => {
    const li = document.createElement("li");
    li.innerHTML = `${t.desc} <span>${t.amount > 0 ? '+' : '-'}₹${Math.abs(t.amount).toFixed(2)}</span>`;
    li.style.color = t.amount > 0 ? "green" : "red";
    list.appendChild(li);

    if (t.amount > 0) totalIncome += t.amount;
    else totalExpense += Math.abs(t.amount);
  });

  income.innerText = `₹${totalIncome.toFixed(2)}`;
  expense.innerText = `₹${totalExpense.toFixed(2)}`;
  balance.innerText = `₹${(totalIncome - totalExpense).toFixed(2)}`;
}
