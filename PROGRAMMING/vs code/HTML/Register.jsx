import React from 'react';
import '../styles/Login.css';

const Register = () => {
  return (
    <div className="container register">
      <h1 style={{ fontFamily: 'bree serif' }}>Taskify</h1>
      <h2>Create a new account</h2>
      <p>
        Or <a href="/login">sign in to your existing account</a>
      </p>
      <form>
        <input type="text" placeholder="Username" required /><br />
        <input type="email" placeholder="Email address" required /><br />
        <input type="password" placeholder="Password" required /><br />
        <input type="password" placeholder="Confirm Password" required /><br />
        <button type="submit">Register</button>
      </form>
    </div>
  );
};

export default Register;
