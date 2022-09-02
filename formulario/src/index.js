import React from 'react';
import ReactDOM from 'react-dom/client';
import Formulario from './Formulario';
import './index.css';



const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <div className="contenedor">
       <Formulario></Formulario>
    </div>
  </React.StrictMode>
);


