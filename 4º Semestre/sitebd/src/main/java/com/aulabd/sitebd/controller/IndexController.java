package com.aulabd.sitebd.controller;

import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;

import com.aulabd.sitebd.model.Cliente;
import com.aulabd.sitebd.model.ClienteService;

@Controller
@ComponentScan("com.aulabd.sitebd.model")
public class IndexController {
    
    @Autowired
    private ApplicationContext context;

    @GetMapping("/")
    public String index(){
        return "index";
    }

    @GetMapping("/cadastrar")
    public String cadastrar(Model model){
        model.addAttribute("cliente", new Cliente());
        return "cadastro";
    }

    @PostMapping("/cadastrar")
    public String cadastrar(Model model, @ModelAttribute Cliente cliente){
        ClienteService cs = context.getBean(ClienteService.class);
        cs.inserirCliente(cliente);
        return "sucesso";
    }

    @GetMapping("/listar")
    public String listar(Model model){
        ClienteService cs = context.getBean(ClienteService.class);
        List<Map<String, Object>> lista = cs.getClientes();
        model.addAttribute("lista", lista);

        return "listar";
    }
}
