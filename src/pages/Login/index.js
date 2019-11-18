import React, { useState, useEffect } from 'react';
import './style.css'
import api from '../../services/api';

export default function Login({ history }) {
  const [carregando, setCattegando] = useState(false);
  const [user, setUser] = useState('');

  async function verificarUsuario() {
    const exist = await api.get(`/users/${user}`)
    return exist
  }

  async function sigIn(event) {
    event.preventDefault();

    try {
      const response = await verificarUsuario()
      localStorage.setItem('@username', response.data.login)
      history.push('/feed');
    } catch (err) {
      console.log("Erro", err.response)
    }

  }

  function InputChange(e) {
    setUser(e.target.value);
  }


  return (
    <section>
      <form onSubmit={sigIn}>
        <h1>Login na Plataforma GitHub</h1>
        <div className="input-b">
          <input
            value={user}
            onChange={InputChange}
            type="text"
            placeholder="Usuário do GitHub"></input>
        </div>
        <button type="submit"  >Login</button>
        <p>Aceito os <a href="https://www.prosoftsolucoes.com">Termos de Uso</a> de Mateus e Helton.</p>
      </form>
    </section>
  );
}
